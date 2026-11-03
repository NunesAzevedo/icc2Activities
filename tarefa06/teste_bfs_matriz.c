#include <stdio.h>
#include "grafo_matriz.h"

void bfs_matriz(
    const GrafoMatriz *g,
    int origem,
    int visitado[],
    int dist[],
    int pai[],
    int ordem[],
    int *tam_ordem
);

int main(void) {
    GrafoMatriz *g = grafo_matriz_cria(8);

    int arestas[][2] = {
        {0,1}, {0,2}, {1,3}, {1,4}, {2,4},
        {2,5}, {3,6}, {4,6}, {4,7}, {5,7}
    };

    int m = sizeof(arestas) / sizeof(arestas[0]);

    for (int i = 0; i < m; i++)
        grafo_matriz_adiciona_aresta(g, arestas[i][0], arestas[i][1]);

    int vis[8], dist[8], pai[8], ordem[8], tam = 0;

    bfs_matriz(g, 0, vis, dist, pai, ordem, &tam);

    printf("Distâncias a partir de A:\n");

    for (int v = 0; v < 8; v++)
        printf("%c: %d\n", 'A' + v, dist[v]);

    grafo_matriz_libera(g);
    return 0;
}
