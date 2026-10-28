#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "busca.h"

#define CONSULTAS 1000
#define REPETICOES 5

double tempo_ms(clock_t inicio, clock_t fim) {
    return 1000.0 * (double)(fim - inicio) / CLOCKS_PER_SEC;
}

int main(void) {
    const int tamanhos[] = {100, 500, 1000, 5000, 10000, 20000};
    const int nt = sizeof(tamanhos) / sizeof(tamanhos[0]);

    FILE *arq = fopen("resultados_buscas.csv", "w");
    if (!arq) {
        perror("resultados_buscas.csv");
        return 1;
    }

    fprintf(arq,
        "algoritmo,n,tipo,repeticao,tempo_total_ms,"
        "tempo_medio_us,inspecoes_medias\n");

    srand(42);

    for (int s = 0; s < nt; s++) {
        int n = tamanhos[s];
        int *v = malloc(n * sizeof(int));

        if (!v) {
            fclose(arq);
            return 2;
        }

        for (int i = 0; i < n; i++)
            v[i] = 2 * i;

        for (int tipo = 0; tipo < 2; tipo++) {
            const char *nome_tipo =
                tipo == 0 ? "sucesso" : "fracasso";

            for (int rep = 1; rep <= REPETICOES; rep++) {

                long long total_seq = 0;
                long long total_bin = 0;

                /* Busca sequencial */
                clock_t ini_seq = clock();

                for (int q = 0; q < CONSULTAS; q++) {
                    int pos = rand() % n;
                    int chave =
                        tipo == 0 ? 2 * pos : 2 * pos + 1;

                    ResultadoBusca r =
                        busca_sequencial(v, n, chave);

                    total_seq += r.inspecoes;
                }

                clock_t fim_seq = clock();

                double ms_seq = tempo_ms(ini_seq, fim_seq);

                fprintf(arq,
                    "sequencial,%d,%s,%d,%.6f,%.6f,%.6f\n",
                    n, nome_tipo, rep,
                    ms_seq,
                    1000.0 * ms_seq / CONSULTAS,
                    (double)total_seq / CONSULTAS);

                /* Busca binária */
                clock_t ini_bin = clock();

                for (int q = 0; q < CONSULTAS; q++) {
                    int pos = rand() % n;
                    int chave =
                        tipo == 0 ? 2 * pos : 2 * pos + 1;

                    ResultadoBusca r =
                        busca_binaria_recursiva(
                            v, 0, n - 1, chave);

                    total_bin += r.inspecoes;
                }

                clock_t fim_bin = clock();

                double ms_bin = tempo_ms(ini_bin, fim_bin);

                fprintf(arq,
                    "binaria,%d,%s,%d,%.6f,%.6f,%.6f\n",
                    n, nome_tipo, rep,
                    ms_bin,
                    1000.0 * ms_bin / CONSULTAS,
                    (double)total_bin / CONSULTAS);
            }
        }

        free(v);
    }

    fclose(arq);
    printf("Arquivo resultados_buscas.csv criado.\n");
    return 0;
}
