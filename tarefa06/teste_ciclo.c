#include <stdio.h>
#include "grafo_lista.h"

int possui_ciclo_bfs(const GrafoLista *g);

int main(void) {
    GrafoLista *arvore = grafo_lista_cria(5);
    grafo_lista_adiciona_aresta(arvore, 0, 1);
    grafo_lista_adiciona_aresta(arvore, 1, 2);
    grafo_lista_adiciona_aresta(arvore, 1, 3);
    grafo_lista_adiciona_aresta(arvore, 3, 4);

    GrafoLista *ciclo = grafo_lista_cria(4);
    grafo_lista_adiciona_aresta(ciclo, 0, 1);
    grafo_lista_adiciona_aresta(ciclo, 1, 2);
    grafo_lista_adiciona_aresta(ciclo, 2, 0);
    grafo_lista_adiciona_aresta(ciclo, 2, 3);

    printf("Árvore possui ciclo? %s\n",
           possui_ciclo_bfs(arvore) ? "sim" : "não");

    printf("Segundo grafo possui ciclo? %s\n",
           possui_ciclo_bfs(ciclo) ? "sim" : "não");

    grafo_lista_libera(arvore);
    grafo_lista_libera(ciclo);

    return 0;
}
