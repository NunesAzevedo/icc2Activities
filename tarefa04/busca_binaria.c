#include "busca.h"

ResultadoBusca busca_binaria_recursiva(const int v[], int inicio, int fim,
                                       int chave)
{
    ResultadoBusca r;
    r.indice = -1;
    r.inspecoes = 0;

    /* TODO:
       Implemente a busca binária recursiva.

       ATENÇÃO:
       Como cada chamada recursiva cria um novo ResultadoBusca,
       você deve somar as inspeções realizadas na chamada atual
       às inspeções retornadas pela chamada seguinte.
    */

    if (inicio > fim)
    {
        return r;
    }
    int n = (fim - inicio) / 2;
    r.inspecoes++;
    int meio = inicio + (fim - inicio) / 2;
    if (v[meio] == chave)
    {
        r.indice = meio;
        return r;
    }
    else if (v[meio] > chave)
    {
        return busca_binaria_recursiva(v, inicio, meio - 1, chave);
    }
    else
    {
        return busca_binaria_recursiva(v, meio + 1, fim, chave);
    }
}
