#include "grafo_matriz.h"
#include <stdlib.h>

GrafoMatriz *grafo_matriz_cria(int n)
{
    if (n <= 0)
        return NULL;

    GrafoMatriz *g = malloc(sizeof(GrafoMatriz));
    if (g == NULL)
        return NULL;

    g->n = n;
    g->matriz = calloc((size_t)n * n, sizeof(unsigned char));
    if (g->matriz == NULL)
    {
        free(g);
        return NULL;
    }
    return g;
}

void grafo_matriz_adiciona_aresta(GrafoMatriz *g, int u, int v)
{
    if (u < 0 || u >= g->n || v < 0 || v >= g->n)
        return;

    g->matriz[(size_t)u * g->n + v] = 1;
    g->matriz[(size_t)v * g->n + u] = 1;
}

int grafo_matriz_tem_aresta(const GrafoMatriz *g, int u, int v)
{
    if (u < 0 || u >= g->n || v < 0 || v >= g->n)
        return 0;

    return g->matriz[(size_t)u * g->n + v];
}

void grafo_matriz_libera(GrafoMatriz *g)
{
    if (g == NULL)
        return;

    free(g->matriz);
    free(g);
}
