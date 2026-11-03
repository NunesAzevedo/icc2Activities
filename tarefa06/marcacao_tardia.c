#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "grafo_lista.h"

static int bfs_correta(const GrafoLista *g, int s) {
    int *vis = calloc(g->n, sizeof(int));
    Fila *f = fila_cria(g->n * 4);
    int enfileiramentos = 0;

    vis[s] = 1;
    fila_enfileira(f, s);
    enfileiramentos++;

    while (!fila_vazia(f)) {
        int u;
        fila_desenfileira(f, &u);

        for (NoAdj *p = g->inicio[u]; p; p = p->prox) {
            int v = p->vertice;

            if (!vis[v]) {
                vis[v] = 1;  /* marca ANTES */
                fila_enfileira(f, v);
                enfileiramentos++;
            }
        }
    }

    free(vis);
    fila_libera(f);
    return enfileiramentos;
}

static int bfs_marcando_tarde(const GrafoLista *g, int s) {
    int *vis = calloc(g->n, sizeof(int));
    Fila *f = fila_cria(g->n * 10);
    int enfileiramentos = 0;

    fila_enfileira(f, s);
    enfileiramentos++;

    while (!fila_vazia(f)) {
        int u;
        fila_desenfileira(f, &u);

        if (vis[u])
            continue;

        vis[u] = 1;  /* ERRADO: marca somente ao remover */

        for (NoAdj *p = g->inicio[u]; p; p = p->prox) {
            int v = p->vertice;

            if (!vis[v]) {
                fila_enfileira(f, v);
                enfileiramentos++;
            }
        }
    }

    free(vis);
    fila_libera(f);
    return enfileiramentos;
}

int main(void) {
    GrafoLista *g = grafo_lista_cria(4);

    grafo_lista_adiciona_aresta(g, 0, 1); /* A-B */
    grafo_lista_adiciona_aresta(g, 0, 2); /* A-C */
    grafo_lista_adiciona_aresta(g, 1, 3); /* B-D */
    grafo_lista_adiciona_aresta(g, 2, 3); /* C-D */

    printf("Marcação no enfileiramento: %d inserções na fila\n",
           bfs_correta(g, 0));

    printf("Marcação tardia:           %d inserções na fila\n",
           bfs_marcando_tarde(g, 0));

    grafo_lista_libera(g);
    return 0;
}
