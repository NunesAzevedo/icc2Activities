#include "ordenacao.h"
#include <stdio.h>

void insertion_sort(int v[], int n, Estatisticas *est)
{
    /* TODO:
       implemente o Insertion Sort e atualize as estatísticas.
    */
    // BUTTER_LOG("Variaveis de entrada", "n: %d", n);
    // for (int i = 0; i < n; i++)
    // {
    //     BUTTER_LOG("Variaveis de entrada", "v[%d]: %d", i, v[i]);
    // }
    // BUTTER_LOG("Variaveis de entrada", "est->comparacoes: ", est->comparacoes);
    // BUTTER_LOG("Variaveis de entrada", "est->trocas: ", est->trocas);


    printf("%s", FONT_YELLOW);
    printf("Vetor inicial: \n");
    for (int i = 0; i < n; i++)
    {
      printf("%d ", v[i]);
    }
    printf("%s", COLOR_RESET);
    printf("\n");


    for (int j = 1; j < n; j++)
    {
        int key = v[j];
        int i = j - 1;

        while (i >= 0 && v[i] > key)
        {
            // printf("v[%d]: \n", v[i]);
            est->comparacoes++;
            est->trocas++;
            v[i + 1] = v[i];
            i--;
        }
        est->trocas++;
        v[i + 1] = key;
    }

    printf("%s", FONT_GREEN);
    printf("Vetor final: \n");
    for (int i = 0; i < n; i++)
    {
      printf("%d ", v[i]);
    }
    printf("%s", COLOR_RESET);
    printf("\n\n");
    // BUTTER_LOG("Saida", "est->comparacoes: ", est->comparacoes);
    // BUTTER_LOG("Saida", "est->trocas: ", est->trocas);
    // BUTTER_LOG("Fim do insertion sort");
}
