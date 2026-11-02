#include "buscas.h"
#include <stdlib.h>

int construir_indice(const long long *a, int n, int b, Bloco **indice)
{
    if (n == 0)
    {
        indice.quantidade = 0;
        return 0;
    }
    int m = (n - 1) / b;
    for (int i = 0; i < m; i++)
    {
        *indice[i] = malloc(m * sizeof(Bloco));
        if (indice[i] == NULL)
            err("\n\n***\nFalha ao alocar memoria para: indice[%d]\n***\n", i);
    }
    
    for (int i = 0; i < m - 1; i++)
    {
      *indice[i]->inicio = i * b;
      if (b < n - *indice[i]->inicio)
      {
        *indice[i]->quantidade = b;

      } else
      {
        *indice[i]->quantidade = n - *indice[i]->inicio;
      }
      *indice[i]->maximo = a[*indice[i]->inicio + *indice[i]->quantidade - 1];
    }

    for (int i = 0; i < m; i++)
    {
        free(*indice[i]);
    }
    return m;
}
