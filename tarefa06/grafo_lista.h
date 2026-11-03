#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

typedef struct NoAdj {
    int vertice;
    struct NoAdj *prox;
} NoAdj;

typedef struct {
    int n;
    NoAdj **inicio;
    NoAdj **fim;
} GrafoLista;

GrafoLista *grafo_lista_cria(int n);
int grafo_lista_adiciona_aresta(GrafoLista *g, int u, int v);
void grafo_lista_imprime(const GrafoLista *g);
void grafo_lista_libera(GrafoLista *g);

#endif
