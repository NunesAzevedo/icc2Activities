#include "fila.h"
#include "grafo_matriz.h"
#include <stdlib.h>

void bfs_matriz(const GrafoMatriz *g, int origem, int visitado[], int dist[],
                int pai[], int ordem[], int *tam_ordem)
{
    *tam_ordem = 0;
    for (int v = 0; v < g->n; v++)
    {
        visitado[v] = 0;
        dist[v] = -1;
        pai[v] = -1;
    }

    if (origem < 0 || origem >= g->n)
        return;

    Fila *f = fila_cria(g->n);
    if (f == NULL)
        return;

    visitado[origem] = 1;
    dist[origem] = 0;
    fila_enfileira(f, origem);

    while (!fila_vazia(f))
    {
        int u;
        fila_desenfileira(f, &u);
        ordem[(*tam_ordem)++] = u;

        for (int v = 0; v < g->n; v++)
        {
            if (grafo_matriz_tem_aresta(g, u, v) && !visitado[v])
            {
                visitado[v] = 1;
                dist[v] = dist[u] + 1;
                pai[v] = u;
                fila_enfileira(f, v);
            }
        }
    }

    fila_libera(f);
}
