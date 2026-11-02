#ifndef BUSCAS_H
#define BUSCAS_H
#include <stddef.h>
typedef struct
{
    long long maximo;
    int inicio;
    int quantidade;
} Bloco;

int comparar(long long a, long long b, unsigned long long *c);
int sequencial(const long long *a, int n, long long x, unsigned long long *c);
int binaria(const long long *a, int lo, int hi, long long x,
            unsigned long long *c);
int construir_indice(const long long *a, int n, int b, Bloco **indice);
int indexada(const long long *a, const Bloco *indice, int m, long long x,
             unsigned long long *c);
int salto(const long long *a, int n, int b, long long x, unsigned long long *c);
int interpolacao(const long long *a, int n, long long x, unsigned long long *c);
int exponencial(const long long *a, int n, long long x, unsigned long long *c);
#endif
