#ifndef PILHA_H
#define PILHA_H
#include "grafo_lista.h"
typedef struct { int vertice; const NoAdj *proximo; } Quadro;
typedef struct { Quadro *dados; int capacidade; int quantidade; } Pilha;
Pilha *pilha_cria(int capacidade);
int pilha_vazia(const Pilha *p);
int pilha_cheia(const Pilha *p);
int pilha_empilha(Pilha *p, Quadro q);
Quadro *pilha_topo(Pilha *p);
int pilha_desempilha(Pilha *p, Quadro *saida);
void pilha_libera(Pilha *p);
#endif
