#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ordenacao.h"

#define REPETICOES 5

typedef void (*Algoritmo)(int [], int, Estatisticas *);

int esta_ordenado(const int v[], int n) {
    for (int i = 1; i < n; i++)
        if (v[i - 1] > v[i])
            return 0;
    return 1;
}

void gera_entrada(int v[], int n, const char *tipo) {
    if (strcmp(tipo, "ordenado") == 0) {
        for (int i = 0; i < n; i++)
            v[i] = i;
    } else if (strcmp(tipo, "inverso") == 0) {
        for (int i = 0; i < n; i++)
            v[i] = n - i;
    } else {
        for (int i = 0; i < n; i++)
            v[i] = rand();
    }
}

double mede_tempo_us(Algoritmo algoritmo, int v[], int n,
                     Estatisticas *est) {
    clock_t inicio = clock();
    algoritmo(v, n, est);
    clock_t fim = clock();

    return 1e6 * (double)(fim - inicio) / CLOCKS_PER_SEC;
}

int main(void) {
    const int tamanhos[] = {500, 1000, 1500, 2000, 3000};
    const int nt = sizeof(tamanhos) / sizeof(tamanhos[0]);

    const char *tipos[] = {"aleatorio", "ordenado", "inverso"};

    const char *nomes[] = {"bubble", "insertion", "selection"};
    Algoritmo algoritmos[] = {bubble_sort, insertion_sort, selection_sort};

    FILE *arq = fopen("resultados_parte1.csv", "w");
    if (!arq) {
        perror("Nao foi possivel criar o CSV");
        return 1;
    }

    fprintf(arq,
            "algoritmo,n,tipo,execucao,tempo_us,comparacoes,trocas\n");

    srand(42);

    for (int a = 0; a < 3; a++) {
        for (int t = 0; t < 3; t++) {
            for (int s = 0; s < nt; s++) {
                int n = tamanhos[s];

                int *base = malloc(n * sizeof(int));
                int *v = malloc(n * sizeof(int));

                gera_entrada(base, n, tipos[t]);

                for (int r = 1; r <= REPETICOES; r++) {
                    memcpy(v, base, n * sizeof(int));

                    Estatisticas est = {0, 0};
                    double tempo = mede_tempo_us(
                        algoritmos[a], v, n, &est);

                    if (!esta_ordenado(v, n)) {
                        fprintf(stderr,
                                "ERRO: %s nao ordenou corretamente "
                                "(n=%d, tipo=%s).\n",
                                nomes[a], n, tipos[t]);
                        fclose(arq);
                        free(base);
                        free(v);
                        return 2;
                    }

                    fprintf(arq, "%s,%d,%s,%d,%.3f,%lld,%lld\n",
                            nomes[a], n, tipos[t], r, tempo,
                            est.comparacoes, est.trocas);
                }

                free(base);
                free(v);
            }
        }
    }

    fclose(arq);
    printf("Resultados gravados em resultados_parte1.csv\n");
    return 0;
}
