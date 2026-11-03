#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

typedef struct {
    int n;
    unsigned char *matriz;
} GrafoMatriz;

GrafoMatriz *grafo_matriz_cria(int n);
void grafo_matriz_adiciona_aresta(GrafoMatriz *g, int u, int v);
int grafo_matriz_tem_aresta(const GrafoMatriz *g, int u, int v);
void grafo_matriz_libera(GrafoMatriz *g);

#endif
