#include "buscas.h"

int interpolacao(const long long *a, int n, long long x, unsigned long long *c)
{
    int lo = 0;
    int hi = n - 1;

    while (lo <= hi)
    {
        if (comparar(x, a[lo], c) < 0)
            return -1;
        if (comparar(x, a[hi], c) > 0)
            return -1;
        if (comparar(a[lo], a[hi], c) == 0)
        {
            if (comparar(x, a[lo], c) == 0)
                return lo;
            return -1;
        }

        long double razao = ((long double)x - (long double)a[lo]) /
                            ((long double)a[hi] - (long double)a[lo]);
        int pos = lo + (int)(razao * ((long double)hi - (long double)lo));
        if (pos < lo)
            pos = lo;
        if (pos > hi)
            pos = hi;

        int root = comparar(a[pos], x, c);
        if (root == 0)
            return pos;
        if (root < 0)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
}
