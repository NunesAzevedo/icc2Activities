#include "busca.h"
#include <stdio.h>

ResultadoBusca busca_sequencial(const int v[], int n, int chave)
{
    ResultadoBusca r;
    r.indice = -1;
    r.inspecoes = 0;

    /* TODO:
       Percorra o vetor.
       Para cada posição examinada, incremente r.inspecoes.
       Ao encontrar a chave, armazene seu índice e retorne.
    */

    printf("%sChave:%s %s%d%s\n", FONT_YELLOW, COLOR_RESET, FONT_BLUE, chave,
           COLOR_RESET);

    printf("%s", FONT_YELLOW);
    printf("Vetor: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("%s", COLOR_RESET);
    printf("\n");

    int isKeyFound = 0;
    int i = 0;
    while (i < n)
    {
        r.inspecoes++;
        if (v[i] == chave)
            isKeyFound = 1;
        if (isKeyFound == 1)
        {
            r.indice = i;
            break;
        }
        i++;
    }

    return r;
}
