#include "fila.h"
#include "grafo_lista.h"
#include <stdlib.h>

int possui_ciclo_bfs(const GrafoLista *g)
{
    int *visitado = calloc(g->n, sizeof(int));
    int *pai = malloc(g->n * sizeof(int));
    Fila *f = fila_cria(g->n);
    if (visitado == NULL || pai == NULL || f == NULL)
    {
        free(visitado);
        free(pai);
        fila_libera(f);
        return -1;
    }

    int ciclo = 0;
    for (int s = 0; s < g->n && !ciclo; s++)
    {
        if (visitado[s])
            continue;

        visitado[s] = 1;
        pai[s] = -1;
        fila_enfileira(f, s);

        while (!fila_vazia(f) && !ciclo)
        {
            int u;
            fila_desenfileira(f, &u);

            for (NoAdj *p = g->inicio[u]; p != NULL; p = p->prox)
            {
                int v = p->vertice;
                if (!visitado[v])
                {
                    visitado[v] = 1;
                    pai[v] = u;
                    fila_enfileira(f, v);
                }
                else if (v != pai[u])
                {
                    ciclo = 1;
                    break;
                }
            }
        }
    }

    free(visitado);
    free(pai);
    fila_libera(f);
    return ciclo;
}
