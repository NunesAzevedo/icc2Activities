#include "ordenacao.h"

void selection_sort(int v[], int n, Estatisticas *est)
{
    /* TODO:
       implemente o Selection Sort e atualize as estatísticas.
    */
    printf("%s", FONT_YELLOW);
    printf("Vetor inicial: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("%s", COLOR_RESET);
    printf("\n");

    for (int i = 0; i <= n - 2; i++)
    {
        int min = i;

        for (int j = i + 1; j <= n - 1; j++)
        {
            est->comparacoes++;
            if (v[min] > v[j])
                min = j;
        }
        if (min != i)
        {
            est->trocas++;
            int tmp = v[i];
            v[i] = v[min];
            v[min] = tmp;
        }
    }

    printf("%s", FONT_GREEN);
    printf("Vetor final: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("%s", COLOR_RESET);
    printf("\n\n");
}
