#include <stdio.h>
#include "busca.h"

void testa(const int v[], int n, int chave, int esperado) {
    ResultadoBusca r = busca_sequencial(v, n, chave);

    printf("chave=%d | indice=%d | esperado=%d | inspecoes=%lld | %s\n",
           chave,
           r.indice,
           esperado,
           r.inspecoes,
           r.indice == esperado ? "OK" : "ERRO");
}

int main(void) {
    int v[] = {15, 22, 37, 41, 58, 63, 79, 84};
    int n = sizeof(v) / sizeof(v[0]);

    testa(v, n, 15, 0);   // primeira posição
    testa(v, n, 41, 3);   // posição intermediária
    testa(v, n, 84, 7);   // última posição
    testa(v, n, 99, -1);  // ausente

    int repetidos[] = {4, 7, 7, 7, 20};
    testa(repetidos, 5, 7, 1);

    return 0;
}
