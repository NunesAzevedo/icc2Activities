#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

Fila *fila_cria(int capacidade)
{
    if (capacidade <= 0)
    {
        printf("[ERRO]: Capacidade inserida eh menor ou igual a 0\n");
        return NULL;
    }
    Fila *f = malloc(sizeof(Fila));
    if (f == NULL)
        return NULL;

    f->dados = malloc(capacidade * sizeof(int));
    if (f->dados == NULL)
    {
        free(f);
        return NULL;
    }

    f->capacidade = capacidade;
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
    return f;
}

int fila_vazia(const Fila *f)
{
    if (f->quantidade == 0)
        return 1;
    else
        return 0;
}

int fila_cheia(const Fila *f)
{
    if (f->quantidade == f->capacidade)
        return 1;
    else
        return 0;
}

int fila_enfileira(Fila *f, int valor)
{
    if (fila_cheia(f))
        return 0;

    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % f->capacidade;
    f->quantidade++;
    return 1;
}

int fila_desenfileira(Fila *f, int *valor)
{
    if (fila_vazia(f))
        return 0;

    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % f->capacidade;
    f->quantidade--;
    return 1;
}

void fila_imprime(const Fila *f)
{
    for (int i = 0; i < f->quantidade; i++)
    {
        printf("%d ", f->dados[(f->inicio + i) % f->capacidade]);
    }
    printf("\n");
}

void fila_libera(Fila *f)
{
    if (f == NULL)
        return;
    free(f->dados);
    free(f);
}
