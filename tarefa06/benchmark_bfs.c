#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"
#include "grafo_lista.h"
#include "grafo_matriz.h"

static long long bfs_lista_conta(const GrafoLista *g, int s) {
    int *vis = calloc(g->n, sizeof(int));
    Fila *f = fila_cria(g->n);
    long long checks = 0;

    vis[s] = 1;
    fila_enfileira(f, s);

    while (!fila_vazia(f)) {
        int u;
        fila_desenfileira(f, &u);

        for (NoAdj *p = g->inicio[u]; p; p = p->prox) {
            checks++;
            int v = p->vertice;

            if (!vis[v]) {
                vis[v] = 1;
                fila_enfileira(f, v);
            }
        }
    }

    free(vis);
    fila_libera(f);
    return checks;
}

static long long bfs_matriz_conta(const GrafoMatriz *g, int s) {
    int *vis = calloc(g->n, sizeof(int));
    Fila *f = fila_cria(g->n);
    long long checks = 0;

    vis[s] = 1;
    fila_enfileira(f, s);

    while (!fila_vazia(f)) {
        int u;
        fila_desenfileira(f, &u);

        for (int v = 0; v < g->n; v++) {
            checks++;

            if (grafo_matriz_tem_aresta(g, u, v) && !vis[v]) {
                vis[v] = 1;
                fila_enfileira(f, v);
            }
        }
    }

    free(vis);
    fila_libera(f);
    return checks;
}

static double us(clock_t a, clock_t b) {
    return 1e6 * (double)(b - a) / CLOCKS_PER_SEC;
}

int main(void) {
    const int tamanhos[] = {100, 250, 500, 750, 1000};
    const int nt = sizeof(tamanhos) / sizeof(tamanhos[0]);
    const int repeticoes = 5;

    FILE *arq = fopen("benchmark_bfs.csv", "w");
    if (!arq) return 1;

    fprintf(arq, "representacao,V,E,repeticao,tempo_us,verificacoes\n");

    srand(42);

    for (int k = 0; k < nt; k++) {
        int n = tamanhos[k];
        int alvo_arestas = 2 * n;

        for (int rep = 1; rep <= repeticoes; rep++) {
            GrafoLista *gl = grafo_lista_cria(n);
            GrafoMatriz *gm = grafo_matriz_cria(n);

            unsigned char *usada = calloc((size_t)n * n, 1);
            int e = 0;

            /* cadeia para garantir conectividade */
            for (int i = 0; i < n - 1; i++) {
                grafo_lista_adiciona_aresta(gl, i, i + 1);
                grafo_matriz_adiciona_aresta(gm, i, i + 1);
                usada[(size_t)i * n + (i + 1)] = 1;
                usada[(size_t)(i + 1) * n + i] = 1;
                e++;
            }

            while (e < alvo_arestas) {
                int u = rand() % n;
                int v = rand() % n;

                if (u == v) continue;

                if (!usada[(size_t)u * n + v]) {
                    usada[(size_t)u * n + v] = 1;
                    usada[(size_t)v * n + u] = 1;

                    grafo_lista_adiciona_aresta(gl, u, v);
                    grafo_matriz_adiciona_aresta(gm, u, v);
                    e++;
                }
            }

            clock_t a = clock();
            long long c_lista = bfs_lista_conta(gl, 0);
            clock_t b = clock();

            fprintf(arq, "lista,%d,%d,%d,%.3f,%lld\n",
                    n, e, rep, us(a,b), c_lista);

            a = clock();
            long long c_matriz = bfs_matriz_conta(gm, 0);
            b = clock();

            fprintf(arq, "matriz,%d,%d,%d,%.3f,%lld\n",
                    n, e, rep, us(a,b), c_matriz);

            free(usada);
            grafo_lista_libera(gl);
            grafo_matriz_libera(gm);
        }
    }

    fclose(arq);
    printf("Arquivo benchmark_bfs.csv criado.\n");
    return 0;
}
