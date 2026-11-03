#include "grafo_lista.h"
#include <stdio.h>
#include <stdlib.h>

static int adiciona_direcionada(GrafoLista *g, int u, int v)
{
    NoAdj *no = malloc(sizeof(NoAdj));
    if (no == NULL)
        return 0;

    no->vertice = v;
    no->prox = NULL;

    if (g->inicio[u] == NULL)
        g->inicio[u] = no;
    else
        g->fim[u]->prox = no;
    g->fim[u] = no;
    return 1;
}

GrafoLista *grafo_lista_cria(int n)
{
    if (n <= 0)
        return NULL;

    GrafoLista *g = malloc(sizeof(GrafoLista));
    if (g == NULL)
        return NULL;

    g->n = n;
    g->inicio = calloc(n, sizeof(NoAdj *));
    g->fim = calloc(n, sizeof(NoAdj *));
    if (g->inicio == NULL || g->fim == NULL)
    {
        free(g->inicio);
        free(g->fim);
        free(g);
        return NULL;
    }
    return g;
}

int grafo_lista_adiciona_aresta(GrafoLista *g, int u, int v)
{
    if (u < 0 || u >= g->n || v < 0 || v >= g->n)
        return 0;

    if (!adiciona_direcionada(g, u, v))
        return 0;
    return adiciona_direcionada(g, v, u);
}

void grafo_lista_imprime(const GrafoLista *g)
{
    for (int u = 0; u < g->n; u++)
    {
        printf("%d:", u);
        for (NoAdj *p = g->inicio[u]; p != NULL; p = p->prox)
            printf(" %d", p->vertice);
        printf("\n");
    }
}

void grafo_lista_libera(GrafoLista *g)
{
    if (g == NULL)
        return;

    for (int u = 0; u < g->n; u++)
    {
        NoAdj *p = g->inicio[u];
        while (p != NULL)
        {
            NoAdj *prox = p->prox;
            free(p);
            p = prox;
        }
    }
    free(g->inicio);
    free(g->fim);
    free(g);
}
