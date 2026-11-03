#include <stdio.h>
#include "grafo_lista.h"
#include "bfs.h"

int reconstroi_caminho(
    const int pai[],
    int origem,
    int destino,
    int caminho[],
    int capacidade
);

int main(void) {
    GrafoLista *g = grafo_lista_cria(8);

    int arestas[][2] = {
        {0,1}, {0,2}, {1,3}, {1,4}, {2,4},
        {2,5}, {3,6}, {4,6}, {4,7}, {5,7}
    };

    int m = sizeof(arestas) / sizeof(arestas[0]);

    for (int i = 0; i < m; i++)
        grafo_lista_adiciona_aresta(g, arestas[i][0], arestas[i][1]);

    int vis[8], dist[8], pai[8], ordem[8], tam = 0;

    bfs_lista(g, 0, vis, dist, pai, ordem, &tam);

    int caminho[8];
    int n = reconstroi_caminho(pai, 0, 7, caminho, 8);

    printf("Caminho A -> H: ");

    for (int i = 0; i < n; i++) {
        if (i) printf(" -> ");
        printf("%c", 'A' + caminho[i]);
    }

    printf("\nNúmero de arestas: %d\n", n > 0 ? n - 1 : -1);

    grafo_lista_libera(g);
    return 0;
}
