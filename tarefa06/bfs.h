#ifndef BFS_H
#define BFS_H

#include "grafo_lista.h"

void bfs_lista(
    const GrafoLista *g,
    int origem,
    int visitado[],
    int dist[],
    int pai[],
    int ordem[],
    int *tam_ordem
);

#endif
