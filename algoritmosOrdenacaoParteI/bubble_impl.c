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

    for(int i = 0; i < n; i++)
    {
      int shouldSwap = 0;

      for(int j = i + 1; j < n; j++)
      {
        est->comparacoes++;
        BUTTER_LOG("Estatitica", "Houve comparapcao. est->comparacoes: ", est->comparacoes);
        if(v[i] > v[j])
        {
          est->trocas++;
        BUTTER_LOG("Estatitica", "Houve troca. est->trocas: ", est->trocas);
          v[j] = v[i];
          v[i] = v[j];
          shouldSwap = 1;
        }
        if(shouldSwap == 0) break;
      }
    }

    BUTTER_LOG("Final do bubble sort", "Fim da ordenacao");
}


