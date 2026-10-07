#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int v[], int n, Estatisticas *est)
{
    /* TODO:
       1. implemente o Bubble Sort otimizado;
       2. conte comparações em est->comparacoes;
       3. conte trocas em est->trocas.
    */
    BUTTER_LOG("Variaveis de entrada", "n: %d", n);
    for (int i = 0; i < n; i++)
    {
        BUTTER_LOG("Variaveis de entrada", "v[%d]: %d", i, v[i]);
    }
    BUTTER_LOG("Variaveis de entrada", "est->comparacoes: ", est->comparacoes);
    BUTTER_LOG("Variaveis de entrada", "est->trocas: ", est->trocas);
}

// Main para fins de depuração de código
// int main()
// {
// }
