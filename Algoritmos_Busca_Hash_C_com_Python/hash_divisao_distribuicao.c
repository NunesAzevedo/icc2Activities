#include <stdio.h>
#include <stdlib.h>

#define M 10
#define N_CHAVES 20

int hash_divisao(int chave, int m) {
    /* TODO:
       implemente h(chave) = chave % m
    */
    return 0;
}

int main(void) {
    int contagem[M] = {0};

    srand(42);

    printf("Chaves e posições:\n");

    for (int i = 0; i < N_CHAVES; i++) {
        int chave = 10 + rand() % 991;
        int pos = hash_divisao(chave, M);

        printf("%4d -> %d\n", chave, pos);

        /* TODO:
           incremente a contagem da posição calculada.
        */
    }

    FILE *arq = fopen("distribuicao_divisao.csv", "w");
    if (!arq)
        return 1;

    fprintf(arq, "posicao,quantidade\n");

    for (int i = 0; i < M; i++)
        fprintf(arq, "%d,%d\n", i, contagem[i]);

    fclose(arq);

    printf("Arquivo distribuicao_divisao.csv criado.\n");
    return 0;
}
