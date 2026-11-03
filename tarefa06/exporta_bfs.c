#include <stdio.h>
#include "grafo_lista.h"
#include "bfs.h"

int main(void) {
    GrafoLista *g = grafo_lista_cria(8);

    int arestas[][2] = {
        {0,1}, {0,2}, {1,3}, {1,4}, {2,4},
        {2,5}, {3,6}, {4,6}, {4,7}, {5,7}
    };

    int m = sizeof(arestas) / sizeof(arestas[0]);

    for (int i = 0; i < m; i++)
        grafo_lista_adiciona_aresta(g, arestas[i][0], arestas[i][1]);

    int visitado[8], dist[8], pai[8], ordem[8], tam = 0;

    bfs_lista(g, 0, visitado, dist, pai, ordem, &tam);

    int pos_ordem[8];

    for (int i = 0; i < tam; i++)
        pos_ordem[ordem[i]] = i;

    FILE *arq = fopen("resultado_bfs.csv", "w");
    if (!arq) return 1;

    fprintf(arq, "vertice,distancia,pai,ordem\n");

    for (int v = 0; v < 8; v++) {
        char pai_nome = pai[v] == -1 ? '-' : (char)('A' + pai[v]);

        fprintf(
            arq, "%c,%d,%c,%d\n",
            'A' + v, dist[v], pai_nome, pos_ordem[v]
        );
    }

    fclose(arq);
    grafo_lista_libera(g);

    printf("Arquivo resultado_bfs.csv criado.\n");
    return 0;
}
