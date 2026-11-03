#include "buscas.h"
#include <stdlib.h>

int construir_indice(const long long *a, int n, int b, Bloco **indice)
{
    if (n == 0)
    {
        *indice = NULL;
        return 0;
    }

    int m = (n - 1) / b + 1;
    *indice = malloc(m * sizeof(Bloco));
    if (*indice == NULL)
        return -1;

    for (int i = 0; i < m; i++)
    {
        (*indice)[i].inicio = i * b;
        if (b < n - (*indice)[i].inicio)
        {
            (*indice)[i].quantidade = b;
        }
        else
        {
            (*indice)[i].quantidade = n - (*indice)[i].inicio;
        }
        (*indice)[i].maximo =
            a[(*indice)[i].inicio + (*indice)[i].quantidade - 1];
    }

    return m;
}

int indexada(const long long *a, const Bloco *indice, int m, long long x,
             unsigned long long *c)
{
    for (int j = 0; j < m; j++)
    {
        if (comparar(indice[j].maximo, x, c) >= 0)
        {
            int fim = indice[j].inicio + indice[j].quantidade;
            for (int i = indice[j].inicio; i < fim; i++)
            {
                int root = comparar(a[i], x, c);
                if (root == 0)
                    return i;
                if (root > 0)
                    return -1;
            }
            return -1;
        }
    }
    return -1;
}
