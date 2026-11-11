#include "dfs.h"

int dfs_iterativa(const GrafoLista *g, int primeira, ResultadoDFS *r,
                  FILE *rastro)
{
    if (g == NULL || r == NULL || r->n != g->n || primeira < -1 ||
        primeira >= g->n)
        return 0;

    resultado_reinicia(r);
    if (g->n == 0)
        return 1;

    Pilha *p = pilha_cria(g->n);
    if (p == NULL)
        return 0;

    for (int k = -1; k < g->n; k++)
    {
        int raiz = (k == -1) ? primeira : k;
        if (raiz == -1 || r->estado[raiz] != NAO_DESCOBERTO)
            continue;

        int comp = r->componentes++;
        r->estado[raiz] = EM_PROCESSAMENTO;
        r->d[raiz] = ++r->tempo;
        r->ordem_d[r->tam_d++] = raiz;
        r->componente[raiz] = comp;
        Quadro inicial = {raiz, g->inicio[raiz]};
        pilha_empilha(p, inicial);
        if (p->quantidade > r->max_pilha)
            r->max_pilha = p->quantidade;
        registra_evento(rastro, g, r, p, "descobrir", raiz);

        while (!pilha_vazia(p))
        {
            Quadro *q = pilha_topo(p);
            int u = q->vertice;

            if (q->proximo == NULL)
            {
                r->estado[u] = FINALIZADO;
                r->f[u] = ++r->tempo;
                r->ordem_f[r->tam_f++] = u;
                pilha_desempilha(p, NULL);
                registra_evento(rastro, g, r, p, "finalizar", u);
            }
            else
            {
                const NoAdj *atual = q->proximo;
                int v = atual->vertice;
                q->proximo = atual->prox;
                r->exames++;

                if (r->estado[v] == NAO_DESCOBERTO)
                {
                    r->pai[v] = u;
                    r->estado[v] = EM_PROCESSAMENTO;
                    r->d[v] = ++r->tempo;
                    r->ordem_d[r->tam_d++] = v;
                    r->componente[v] = comp;
                    Quadro novo = {v, g->inicio[v]};
                    pilha_empilha(p, novo);
                    if (p->quantidade > r->max_pilha)
                        r->max_pilha = p->quantidade;
                    registra_evento(rastro, g, r, p, "descobrir", v);
                }
                else if (r->estado[v] == EM_PROCESSAMENTO && v != r->pai[u])
                    r->tem_ciclo = 1;
            }
        }
    }

    pilha_libera(p);
    return 1;
}
