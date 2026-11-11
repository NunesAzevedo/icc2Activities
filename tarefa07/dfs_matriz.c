#include "dfs.h"
#include <stddef.h>

static void visita_matriz(const unsigned char *matriz, int n, int u, int comp,
                          int prof, ResultadoDFS *r)
{
    r->estado[u] = EM_PROCESSAMENTO;
    r->d[u] = ++r->tempo;
    r->ordem_d[r->tam_d++] = u;
    r->componente[u] = comp;
    if (prof > r->max_pilha)
        r->max_pilha = prof;

    for (int v = 0; v < n; v++)
    {
        r->exames++;
        if (matriz[(size_t)u * n + v])
        {
            if (r->estado[v] == NAO_DESCOBERTO)
            {
                r->pai[v] = u;
                visita_matriz(matriz, n, v, comp, prof + 1, r);
            }
            else if (r->estado[v] == EM_PROCESSAMENTO && v != r->pai[u])
                r->tem_ciclo = 1;
        }
    }

    r->estado[u] = FINALIZADO;
    r->f[u] = ++r->tempo;
    r->ordem_f[r->tam_f++] = u;
}

int dfs_matriz(const unsigned char *matriz, int n, int primeira,
               ResultadoDFS *r)
{
    if (r == NULL || n < 0 || r->n != n || (matriz == NULL && n > 0) ||
        primeira < -1 || primeira >= n)
        return 0;

    resultado_reinicia(r);

    if (primeira != -1)
        visita_matriz(matriz, n, primeira, r->componentes++, 1, r);

    for (int u = 0; u < n; u++)
        if (r->estado[u] == NAO_DESCOBERTO)
            visita_matriz(matriz, n, u, r->componentes++, 1, r);

    return 1;
}
