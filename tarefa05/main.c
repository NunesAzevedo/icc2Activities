#include "buscas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int metodo_valido(const char *metodo)
{
    return strcmp(metodo, "sequencial") == 0 ||
           strcmp(metodo, "binaria") == 0 || strcmp(metodo, "indexada") == 0 ||
           strcmp(metodo, "salto") == 0 ||
           strcmp(metodo, "interpolacao") == 0 ||
           strcmp(metodo, "exponencial") == 0;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "\n\n***\nUso: %s metodo bloco\n***\n", argv[0]);
        return 1;
    }

    const char *metodo = argv[1];
    if (!metodo_valido(metodo))
    {
        fprintf(stderr, "\n\n***\nMetodo invalido: %s\n***\n", metodo);
        return 1;
    }

    char *resto;
    long bloco = strtol(argv[2], &resto, 10);
    if (*resto != '\0' || bloco < 1 || bloco > 1000000)
    {
        fprintf(stderr, "\n\n***\nBloco invalido: %s\n***\n", argv[2]);
        return 1;
    }
    int b = (int)bloco;

    int n, q;
    if (scanf("%d %d", &n, &q) != 2 || n < 0 || n > 1000000 || q < 0)
    {
        fprintf(stderr, "\n\n***\nFalha ao ler: n e q\n***\n");
        return 1;
    }

    long long *a = NULL;
    if (n > 0)
    {
        a = malloc(n * sizeof(long long));
        if (a == NULL)
        {
            fprintf(stderr, "\n\n***\nFalha ao alocar memoria para: a\n***\n");
            return 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (scanf("%lld", &a[i]) != 1)
        {
            fprintf(stderr, "\n\n***\nFalha ao ler: a[%d]\n***\n", i);
            free(a);
            return 1;
        }
    }

    Bloco *indice = NULL;
    int m = 0;
    if (strcmp(metodo, "indexada") == 0)
    {
        m = construir_indice(a, n, b, &indice);
        if (m < 0)
        {
            fprintf(stderr,
                    "\n\n***\nFalha ao alocar memoria para: indice\n***\n");
            free(a);
            return 1;
        }
    }

    printf("consulta,chave,posicao,comparacoes\n");
    for (int j = 0; j < q; j++)
    {
        long long x;
        if (scanf("%lld", &x) != 1)
        {
            fprintf(stderr, "\n\n***\nFalha ao ler: consulta %d\n***\n", j);
            free(a);
            free(indice);
            return 1;
        }

        unsigned long long c = 0;
        int posicao = -1;
        if (strcmp(metodo, "sequencial") == 0)
            posicao = sequencial(a, n, x, &c);
        else if (strcmp(metodo, "binaria") == 0)
            posicao = binaria(a, 0, n - 1, x, &c);
        else if (strcmp(metodo, "indexada") == 0)
            posicao = indexada(a, indice, m, x, &c);
        else if (strcmp(metodo, "salto") == 0)
            posicao = salto(a, n, b, x, &c);
        else if (strcmp(metodo, "interpolacao") == 0)
            posicao = interpolacao(a, n, x, &c);
        else
            posicao = exponencial(a, n, x, &c);

        printf("%d,%lld,%d,%llu\n", j, x, posicao, c);
    }

    free(a);
    free(indice);
    return 0;
}
