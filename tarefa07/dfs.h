#ifndef DFS_H
#define DFS_H
#include <stdio.h>
#include "grafo_lista.h"
#include "pilha.h"
enum { NAO_DESCOBERTO = 0, EM_PROCESSAMENTO = 1, FINALIZADO = 2 };
typedef struct {
    int n;
    int *estado, *pai, *d, *f, *componente, *ordem_d, *ordem_f;
    int tempo, tam_d, tam_f, componentes, tem_ciclo, max_pilha;
    long long exames;
} ResultadoDFS;
/* Apoio fornecido. */
int resultado_cria(ResultadoDFS *r, int n);
void resultado_reinicia(ResultadoDFS *r);
void resultado_libera(ResultadoDFS *r);
void registra_evento(FILE *arq, const GrafoLista *g, const ResultadoDFS *r,
                     const Pilha *p, const char *evento, int vertice);
/* Funcoes a implementar. primeira=-1 usa todas as raizes em ordem crescente. */
int dfs_recursiva(const GrafoLista *g, int primeira, ResultadoDFS *r);
int dfs_iterativa(const GrafoLista *g, int primeira, ResultadoDFS *r, FILE *rastro);
int dfs_matriz(const unsigned char *matriz, int n, int primeira, ResultadoDFS *r);
int reconstroi_caminho(const int pai[], int n, int origem, int destino,
                      int caminho[], int capacidade);
#endif
