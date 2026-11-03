#include <stdio.h>
#include "grafo_lista.h"
#include "bfs.h"

static char nome(int v) {
    return (char)('A' + v);
}

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

    printf("Ordem de remoção da fila:\n");
    for (int i = 0; i < tam; i++)
        printf("%c ", nome(ordem[i]));

    printf("\n\nVértice  dist  pai\n");

    for (int v = 0; v < 8; v++) {
        printf("   %c      %2d    ", nome(v), dist[v]);

        if (pai[v] == -1)
            printf("-\n");
        else
            printf("%c\n", nome(pai[v]));
    }

    grafo_lista_libera(g);
    return 0;
}
