#include "buscas.h"

int exponencial(const long long *a, int n, long long x, unsigned long long *c)
{
    if (n == 0)
        return -1;

    int root = comparar(a[0], x, c);
    if (root == 0)
        return 0;
    if (root > 0)
        return -1;

    int k = 1;
    while (k < n)
    {
        if (comparar(a[k], x, c) >= 0)
            break;
        k = 2 * k;
    }

    int hi = n - 1;
    if (k < n - 1)
        hi = k;

    return binaria(a, k / 2, hi, x, c);
}
