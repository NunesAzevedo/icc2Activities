#include "buscas.h"

int salto(const long long *a, int n, int b, long long x, unsigned long long *c)
{
    for (int inicio = 0; inicio < n; inicio += b)
    {
        int fim = n - 1;
        if (inicio + b - 1 < n - 1)
            fim = inicio + b - 1;

        if (comparar(a[fim], x, c) >= 0)
        {
            for (int i = inicio; i <= fim; i++)
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
