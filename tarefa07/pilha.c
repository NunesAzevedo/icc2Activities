#include "pilha.h"
#include <stdlib.h>

Pilha *pilha_cria(int capacidade)
{
    if (capacidade <= 0)
        return NULL;

    Pilha *p = malloc(sizeof(Pilha));
    if (p == NULL)
        return NULL;

    p->dados = malloc(capacidade * sizeof(Quadro));
    if (p->dados == NULL)
    {
        free(p);
        return NULL;
    }

    p->capacidade = capacidade;
    p->quantidade = 0;
    return p;
}

int pilha_vazia(const Pilha *p)
{
    if (p == NULL || p->quantidade == 0)
        return 1;
    else
        return 0;
}

int pilha_cheia(const Pilha *p)
{
    if (p != NULL && p->quantidade == p->capacidade)
        return 1;
    else
        return 0;
}

int pilha_empilha(Pilha *p, Quadro q)
{
    if (p == NULL || pilha_cheia(p))
        return 0;

    p->dados[p->quantidade] = q;
    p->quantidade++;
    return 1;
}

Quadro *pilha_topo(Pilha *p)
{
    if (pilha_vazia(p))
        return NULL;

    return &p->dados[p->quantidade - 1];
}

int pilha_desempilha(Pilha *p, Quadro *saida)
{
    if (pilha_vazia(p))
        return 0;

    p->quantidade--;
    if (saida != NULL)
        *saida = p->dados[p->quantidade];
    return 1;
}

void pilha_libera(Pilha *p)
{
    if (p == NULL)
        return;
    free(p->dados);
    free(p);
}
