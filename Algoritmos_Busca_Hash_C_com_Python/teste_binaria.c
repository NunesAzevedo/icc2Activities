#include <stdio.h>
#include "busca.h"

void testa(const int v[], int n, int chave, int esperado) {
    ResultadoBusca r =
        busca_binaria_recursiva(v, 0, n - 1, chave);

    printf("chave=%d | indice=%d | esperado=%d | inspecoes=%lld | %s\n",
           chave,
           r.indice,
           esperado,
           r.inspecoes,
           r.indice == esperado ? "OK" : "ERRO");
}

int main(void) {
    int v[] = {10, 14, 20, 28, 35, 41, 55, 70, 83, 91};
    int n = sizeof(v) / sizeof(v[0]);

    testa(v, n, 10, 0);
    testa(v, n, 35, 4);
    testa(v, n, 91, 9);
    testa(v, n, 50, -1);

    return 0;
}
