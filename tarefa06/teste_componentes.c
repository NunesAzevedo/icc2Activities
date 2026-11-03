#include <stdio.h>
#include "grafo_lista.h"

int componentes_bfs(
    const GrafoLista *g,
    int componente[]
);

int main(void) {
    GrafoLista *g = grafo_lista_cria(7);

    /* componente 0: A-B-C-D */
    grafo_lista_adiciona_aresta(g, 0, 1);
    grafo_lista_adiciona_aresta(g, 1, 2);
    grafo_lista_adiciona_aresta(g, 2, 3);
    grafo_lista_adiciona_aresta(g, 3, 0);

    /* componente 1: E-F-G */
    grafo_lista_adiciona_aresta(g, 4, 5);
    grafo_lista_adiciona_aresta(g, 5, 6);

    int componente[7];

    int qtd = componentes_bfs(g, componente);

    printf("Número de componentes: %d\n", qtd);

    for (int v = 0; v < 7; v++)
        printf("%c -> componente %d\n", 'A' + v, componente[v]);

    grafo_lista_libera(g);
    return 0;
}
