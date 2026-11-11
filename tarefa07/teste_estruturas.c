#include <assert.h>
#include <stdio.h>
#include "dfs.h"
int main(void){
    assert(!pilha_cria(0));Pilha *p=pilha_cria(2);assert(p&&pilha_vazia(p));
    assert(!pilha_topo(p));assert(!pilha_desempilha(p,NULL));
    Quadro a={2,NULL},b={4,NULL},q;
    assert(pilha_empilha(p,a)&&pilha_empilha(p,b)&&pilha_cheia(p));
    assert(!pilha_empilha(p,a));assert(pilha_topo(p)->vertice==4);
    pilha_topo(p)->vertice=5;assert(pilha_desempilha(p,&q)&&q.vertice==5);
    assert(pilha_desempilha(p,&q)&&q.vertice==2&&pilha_vazia(p));pilha_libera(p);
    assert(!grafo_lista_cria(-1));GrafoLista *g=grafo_lista_cria(4);assert(g);
    assert(grafo_lista_adiciona_aresta(g,0,2));assert(grafo_lista_adiciona_aresta(g,0,1));
    assert(g->inicio[0]->vertice==2&&g->inicio[0]->prox->vertice==1);
    assert(g->fim[0]->vertice==1&&g->inicio[2]->vertice==0);
    assert(!grafo_lista_adiciona_aresta(g,2,0));assert(!grafo_lista_adiciona_aresta(g,0,0));
    assert(!grafo_lista_adiciona_aresta(g,-1,2));
    ResultadoDFS r;assert(resultado_cria(&r,4));
    assert(!dfs_recursiva(g,4,&r));assert(!dfs_iterativa(g,-2,&r,NULL));
    assert(dfs_recursiva(g,0,&r));int d0=r.d[0];assert(dfs_recursiva(g,0,&r)&&r.d[0]==d0);
    assert(dfs_iterativa(g,0,&r,NULL));assert(r.componentes==2&&r.tem_ciclo==0);
    int pais[]={-1,0,1,-1},c[4];
    assert(reconstroi_caminho(pais,4,0,2,c,4)==3&&c[0]==0&&c[1]==1&&c[2]==2);
    assert(reconstroi_caminho(pais,4,0,3,c,4)==0);
    assert(reconstroi_caminho(pais,4,0,0,c,4)==1&&c[0]==0);
    assert(reconstroi_caminho(pais,4,0,2,c,2)==-1);
    assert(reconstroi_caminho(pais,4,0,5,c,4)==-1);
    int ciclo[]={1,0};assert(reconstroi_caminho(ciclo,2,0,1,c,4)==2);
    int invalido[]={-1,2,1};assert(reconstroi_caminho(invalido,3,0,1,c,4)==-1);
    resultado_libera(&r);grafo_lista_libera(g);
    g=grafo_lista_cria(0);assert(g&&resultado_cria(&r,0));
    assert(dfs_recursiva(g,-1,&r)&&dfs_iterativa(g,-1,&r,NULL)&&dfs_matriz(NULL,0,-1,&r));
    assert(r.componentes==0&&r.tempo==0&&r.exames==0&&r.max_pilha==0);
    resultado_libera(&r);grafo_lista_libera(g);
    puts("Estruturas, reinicializacao, caminho e grafo vazio: testes aprovados.");return 0;
}
