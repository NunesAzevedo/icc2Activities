#ifndef FILA_H
#define FILA_H

typedef struct {
    int *dados;
    int capacidade;
    int inicio;
    int fim;
    int quantidade;
} Fila;

Fila *fila_cria(int capacidade);
int fila_vazia(const Fila *f);
int fila_cheia(const Fila *f);
int fila_enfileira(Fila *f, int valor);
int fila_desenfileira(Fila *f, int *valor);
void fila_imprime(const Fila *f);
void fila_libera(Fila *f);

#endif
