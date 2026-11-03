#include <stdio.h>
#include "fila.h"

int main(void) {
    Fila *f = fila_cria(5);
    int x;

    if (!f) return 1;

    fila_enfileira(f, 10);
    fila_enfileira(f, 20);
    fila_enfileira(f, 30);

    printf("Fila inicial: ");
    fila_imprime(f);

    fila_desenfileira(f, &x);
    printf("Removeu %d\n", x);

    fila_desenfileira(f, &x);
    printf("Removeu %d\n", x);

    fila_enfileira(f, 40);
    fila_enfileira(f, 50);
    fila_enfileira(f, 60);

    printf("Após reutilizar posições: ");
    fila_imprime(f);

    printf("Vazia? %s\n", fila_vazia(f) ? "sim" : "não");
    printf("Cheia? %s\n", fila_cheia(f) ? "sim" : "não");

    fila_libera(f);
    return 0;
}
