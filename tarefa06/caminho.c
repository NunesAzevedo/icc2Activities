#include <stdio.h>

int reconstroi_caminho(const int pai[], int origem, int destino, int caminho[],
                       int capacidade)
{
    if (destino < 0)
        return 0;

    int tam = 0;
    for (int v = destino; v != -1; v = pai[v])
    {
        if (tam == capacidade)
            return 0;
        caminho[tam++] = v;
    }

    if (caminho[tam - 1] != origem)
        return 0;

    for (int i = 0; i < tam / 2; i++)
    {
        int aux = caminho[i];
        caminho[i] = caminho[tam - 1 - i];
        caminho[tam - 1 - i] = aux;
    }
    return tam;
}
