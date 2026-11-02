#include "buscas.h"

int comparar(long long a, long long b, unsigned long long *c)
{
    *c++;
    if (a < b) return -1;
    else if (a > b) return 1;
    
    return 0;
}


int sequencial(const long long *a, int n, long long x, unsigned long long *c)
{
  for (int i = 0; i < n - 1; i++)
  {
    if (comparar(a[i], x, c) == 0) return i;
    return -1;
  }
}

int binaria(const long long *a, int lo, int hi, long long x, unsigned long long *c)
{
  while(l0 <= hi)
  {
    int middle = l0 + (hi - lo) / 2;
    int root = comparar(a[middle], x, c);
    if (root == 0) return middle;
    if (root < 0) lo = middle + 1;
    else hi = middle - 1;
    return -1;
  }
}
