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

void imprime_vetor(const int v[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main(void) {
    const int tamanhos[] = {5, 10, 15};
    const int qtd = 3;

    srand(42);

    for (int k = 0; k < qtd; k++) {
        int n = tamanhos[k];
        int *v = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            v[i] = 10 + rand() % 91;  // valores entre 10 e 100

        Estatisticas est = {0, 0};

        printf("\nVetor original (n=%d):\n", n);
        imprime_vetor(v, n);

        bubble_sort(v, n, &est);

        printf("Vetor após Bubble Sort:\n");
        imprime_vetor(v, n);

        printf("Ordenado corretamente? %s\n",
               esta_ordenado(v, n) ? "SIM" : "NAO");
        printf("Comparacoes: %lld | Trocas: %lld\n",
               est.comparacoes, est.trocas);

        free(v);
    }

    return 0;
}
