#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

int esta_ordenado(const int v[], int n) {
    for (int i = 1; i < n; i++)
        if (v[i - 1] > v[i])
            return 0;
    return 1;
}

int main(void) {
    const int tamanhos[] = {5, 10, 15};
    srand(42);

    for (int k = 0; k < 3; k++) {
        int n = tamanhos[k];
        int *v = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            v[i] = 10 + rand() % 91;

        Estatisticas est = {0, 0};
        insertion_sort(v, n, &est);

        printf("n=%d | correto=%s | comparacoes=%lld | movimentacoes=%lld\n",
               n,
               esta_ordenado(v, n) ? "SIM" : "NAO",
               est.comparacoes,
               est.trocas);

        free(v);
    }

    return 0;
}
