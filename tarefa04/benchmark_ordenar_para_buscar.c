#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "busca.h"

int compara_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

double ms(clock_t inicio, clock_t fim) {
    return 1000.0 * (double)(fim - inicio) / CLOCKS_PER_SEC;
}

int main(void) {
    const int n = 20000;
    const int quantidades[] = {1, 10, 100, 1000, 5000};
    const int nq = sizeof(quantidades) / sizeof(quantidades[0]);

    int *original = malloc(n * sizeof(int));
    int *ordenado = malloc(n * sizeof(int));

    if (!original || !ordenado)
        return 1;

    srand(123);

    for (int i = 0; i < n; i++)
        original[i] = rand();

    FILE *arq = fopen("ordenar_para_buscar.csv", "w");
    if (!arq)
        return 2;

    fprintf(arq, "estrategia,numero_buscas,tempo_total_ms\n");

    for (int k = 0; k < nq; k++) {
        int q = quantidades[k];

        /* Estratégia A: somente busca sequencial */
        clock_t ini_a = clock();

        for (int i = 0; i < q; i++) {
            int chave = original[rand() % n];
            busca_sequencial(original, n, chave);
        }

        clock_t fim_a = clock();

        fprintf(arq, "sequencial,%d,%.6f\n",
                q, ms(ini_a, fim_a));

        /* Estratégia B: ordenar uma vez + q buscas binárias */
        memcpy(ordenado, original, n * sizeof(int));

        clock_t ini_b = clock();

        qsort(ordenado, n, sizeof(int), compara_int);

        for (int i = 0; i < q; i++) {
            int chave = original[rand() % n];

            busca_binaria_recursiva(
                ordenado, 0, n - 1, chave);
        }

        clock_t fim_b = clock();

        fprintf(arq, "ordenar+binaria,%d,%.6f\n",
                q, ms(ini_b, fim_b));
    }

    fclose(arq);
    free(original);
    free(ordenado);

    printf("Arquivo ordenar_para_buscar.csv criado.\n");
    return 0;
}
