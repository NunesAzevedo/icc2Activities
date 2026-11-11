#include <stdlib.h>
#include <string.h>
#include "dfs.h"
int resultado_cria(ResultadoDFS *r,int n) {
    if (!r || n<0) return 0;
    memset(r,0,sizeof(*r)); r->n=n;
    size_t tam=(size_t)(n>0?n:1);
    r->estado=malloc(tam*sizeof(int)); r->pai=malloc(tam*sizeof(int));
    r->d=malloc(tam*sizeof(int));r->f=malloc(tam*sizeof(int));
    r->componente=malloc(tam*sizeof(int));r->ordem_d=malloc(tam*sizeof(int));
    r->ordem_f=malloc(tam*sizeof(int));
    if (!r->estado||!r->pai||!r->d||!r->f||!r->componente||!r->ordem_d||!r->ordem_f) {
        resultado_libera(r);return 0;
    }
    resultado_reinicia(r); return 1;
}
void resultado_reinicia(ResultadoDFS *r) {
    r->tempo=r->tam_d=r->tam_f=r->componentes=r->tem_ciclo=r->max_pilha=0;
    r->exames=0;
    for(int i=0;i<r->n;++i){r->estado[i]=NAO_DESCOBERTO;r->pai[i]=-1;
        r->d[i]=r->f[i]=0;r->componente[i]=r->ordem_d[i]=r->ordem_f[i]=-1;}
}
void resultado_libera(ResultadoDFS *r) {
    if(!r)return;
    free(r->estado);free(r->pai);free(r->d);free(r->f);free(r->componente);
    free(r->ordem_d);free(r->ordem_f);memset(r,0,sizeof(*r));
}
void registra_evento(FILE *a,const GrafoLista *g,const ResultadoDFS *r,
                     const Pilha *p,const char *evento,int u) {
    if(!a)return;
    fprintf(a,"%d,%s,%d,%d,\"",r->tempo-1,evento,u,r->tempo);
    for(int k=0;k<p->quantidade;++k){
        Quadro q=p->dados[k];int indice=0;
        for(const NoAdj *x=g->inicio[q.vertice];x && x!=q.proximo;x=x->prox)++indice;
        if(k)fputc(';',a);
        fprintf(a,"%d:%d",q.vertice,indice);
    }
    fprintf(a,"\",\"");
    for(int v=0;v<g->n;++v){if(v)fputc(';',a);fprintf(a,"%d",r->estado[v]);}
    fprintf(a,"\"\n");
}
