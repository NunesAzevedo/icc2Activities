#include "dfs.h"

int reconstroi_caminho(const int pai[], int n, int origem, int destino,
                       int caminho[], int capacidade)
{
    if (pai == NULL || caminho == NULL || capacidade <= 0 || origem < 0 ||
        origem >= n || destino < 0 || destino >= n)
        return -1;

    int tam = 0;
    for (int u = destino; u != -1; u = pai[u])
    {
        if (u < 0 || u >= n || tam == n)
            return -1;
        if (tam == capacidade)
            return -1;
        caminho[tam++] = u;

        if (u == origem)
        {
            for (int i = 0; i < tam / 2; i++)
            {
                int aux = caminho[i];
                caminho[i] = caminho[tam - 1 - i];
                caminho[tam - 1 - i] = aux;
            }
            return tam;
        }
    }
    return 0;
}
