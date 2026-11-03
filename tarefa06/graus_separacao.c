#include "bfs.h"
#include "grafo_lista.h"
#include <stdio.h>

#define N 10

int reconstroi_caminho(const int pai[], int origem, int destino, int caminho[],
                       int capacidade);

int main(void)
{
    const char *nomes[N] = {"Ana",   "Bruno", "Carla", "Diego", "Elisa",
                            "Fabio", "Gabi",  "Hugo",  "Iris",  "Joao"};
    int amizades[][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4},
                         {3, 5}, {4, 6}, {5, 7}, {6, 7}, {7, 8}};
    int m = sizeof(amizades) / sizeof(amizades[0]);

    GrafoLista *g = grafo_lista_cria(N);
    if (g == NULL)
    {
        fprintf(stderr, "\n\n***\nFalha ao alocar memoria para: g\n***\n");
        return 1;
    }

    for (int i = 0; i < m; i++)
        grafo_lista_adiciona_aresta(g, amizades[i][0], amizades[i][1]);

    int origem = 0, destino = 8;
    int visitado[N], dist[N], pai[N], ordem[N], tam = 0;
    bfs_lista(g, origem, visitado, dist, pai, ordem, &tam);

    printf("Graus de separacao entre %s e %s: %d\n", nomes[origem],
           nomes[destino], dist[destino]);

    int caminho[N];
    int k = reconstroi_caminho(pai, origem, destino, caminho, N);
    printf("Caminho minimo: ");
    for (int i = 0; i < k; i++)
    {
        if (i)
            printf(" -> ");
        printf("%s", nomes[caminho[i]]);
    }
    printf("\n");

    printf("Pessoas a distancia 2 de %s:", nomes[origem]);
    for (int v = 0; v < N; v++)
    {
        if (dist[v] == 2)
            printf(" %s", nomes[v]);
    }
    printf("\n");

    FILE *arq = fopen("graus_separacao.csv", "w");
    if (arq == NULL)
    {
        grafo_lista_libera(g);
        return 1;
    }

    fprintf(arq, "pessoa,distancia\n");
    for (int v = 0; v < N; v++)
        fprintf(arq, "%s,%d\n", nomes[v], dist[v]);

    fclose(arq);
    grafo_lista_libera(g);

    printf("Arquivo graus_separacao.csv criado.\n");
    return 0;
}
