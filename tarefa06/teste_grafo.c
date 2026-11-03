#include <stdio.h>
#include "grafo_lista.h"

static char nome(int v) {
    return (char)('A' + v);
}

int main(void) {
    GrafoLista *g = grafo_lista_cria(8);
    if (!g) return 1;

    int arestas[][2] = {
        {0,1}, {0,2}, {1,3}, {1,4}, {2,4},
        {2,5}, {3,6}, {4,6}, {4,7}, {5,7}
    };

    int m = sizeof(arestas) / sizeof(arestas[0]);

    for (int i = 0; i < m; i++)
        grafo_lista_adiciona_aresta(g, arestas[i][0], arestas[i][1]);

    printf("Listas de adjacência:\n");

    for (int u = 0; u < g->n; u++) {
        printf("%c: ", nome(u));

        for (NoAdj *p = g->inicio[u]; p; p = p->prox)
            printf("%c ", nome(p->vertice));

        printf("\n");
    }

    grafo_lista_libera(g);
    return 0;
}
