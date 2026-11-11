#include "dfs.h"

static void visita(const GrafoLista *g, int u, int comp, int prof,
                   ResultadoDFS *r)
{
    r->estado[u] = EM_PROCESSAMENTO;
    r->d[u] = ++r->tempo;
    r->ordem_d[r->tam_d++] = u;
    r->componente[u] = comp;
    if (prof > r->max_pilha)
        r->max_pilha = prof;

    for (const NoAdj *p = g->inicio[u]; p != NULL; p = p->prox)
    {
        r->exames++;
        int v = p->vertice;
        if (r->estado[v] == NAO_DESCOBERTO)
        {
            r->pai[v] = u;
            visita(g, v, comp, prof + 1, r);
        }
        else if (r->estado[v] == EM_PROCESSAMENTO && v != r->pai[u])
            r->tem_ciclo = 1;
    }

    r->estado[u] = FINALIZADO;
    r->f[u] = ++r->tempo;
    r->ordem_f[r->tam_f++] = u;
}

int dfs_recursiva(const GrafoLista *g, int primeira, ResultadoDFS *r)
{
    if (g == NULL || r == NULL || r->n != g->n || primeira < -1 ||
        primeira >= g->n)
        return 0;

    resultado_reinicia(r);

    if (primeira != -1)
        visita(g, primeira, r->componentes++, 1, r);

    for (int u = 0; u < g->n; u++)
        if (r->estado[u] == NAO_DESCOBERTO)
            visita(g, u, r->componentes++, 1, r);

    return 1;
}
