#include "fila.h"
#include "grafo_lista.h"
#include <stdlib.h>

int componentes_bfs(const GrafoLista *g, int componente[])
{
    Fila *f = fila_cria(g->n);
    if (f == NULL)
        return -1;

    for (int v = 0; v < g->n; v++)
        componente[v] = -1;

    int qtd = 0;
    for (int s = 0; s < g->n; s++)
    {
        if (componente[s] != -1)
            continue;

        componente[s] = qtd;
        fila_enfileira(f, s);

        while (!fila_vazia(f))
        {
            int u;
            fila_desenfileira(f, &u);

            for (NoAdj *p = g->inicio[u]; p != NULL; p = p->prox)
            {
                int v = p->vertice;
                if (componente[v] == -1)
                {
                    componente[v] = qtd;
                    fila_enfileira(f, v);
                }
            }
        }
        qtd++;
    }

    fila_libera(f);
    return qtd;
}
