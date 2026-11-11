/* Apoio fornecido: entrada, exportacao e cronometragem. Nao implementa DFS. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dfs.h"
static FILE *arquivo(const char *prefixo,const char *sufixo){
    char nome[1024];int t=snprintf(nome,sizeof(nome),"%s%s",prefixo,sufixo);
    if(t<0||(size_t)t>=sizeof(nome))return NULL;
    return fopen(nome,"w");
}
int main(int argc,char **argv){
    if(argc!=5){fprintf(stderr,"Uso: executa_dfs entrada modo prefixo repeticoes\n");return 1;}
    int rec=strcmp(argv[2],"rec")==0,it=strcmp(argv[2],"iter")==0,mat=strcmp(argv[2],"mat")==0;
    int repeticoes=atoi(argv[4]);if((!rec&&!it&&!mat)||repeticoes<1)return 1;
    FILE *in=fopen(argv[1],"r");if(!in)return 2;
    int n,m,primeira;
    if(fscanf(in,"%d%d%d",&n,&m,&primeira)!=3||n<0||n>6000||m<0){fclose(in);return 2;}
    GrafoLista *g=grafo_lista_cria(n);if(!g){fclose(in);return 3;}
    for(int k=0;k<m;++k){int u,v;
        if(fscanf(in,"%d%d",&u,&v)!=2||!grafo_lista_adiciona_aresta(g,u,v)){
            fclose(in);grafo_lista_libera(g);return 3;}}
    fclose(in);
    unsigned char *matriz=NULL;
    if(mat){matriz=calloc((size_t)n*n+1,1);if(!matriz){grafo_lista_libera(g);return 3;}
        for(int u=0;u<n;++u)for(const NoAdj *p=g->inicio[u];p;p=p->prox)matriz[(size_t)u*n+p->vertice]=1;}
    ResultadoDFS r;
    if(!resultado_cria(&r,n)){free(matriz);grafo_lista_libera(g);return 3;}
    FILE *rastro=NULL;
    if(it&&repeticoes==1){rastro=arquivo(argv[3],".rastro.csv");if(!rastro){resultado_libera(&r);free(matriz);grafo_lista_libera(g);return 4;}
        fprintf(rastro,"passo,evento,vertice,tempo,pilha,estados\n");}
    clock_t a=clock();int ok=1;
    for(int k=0;k<repeticoes;++k){
        if(rec)ok=dfs_recursiva(g,primeira,&r);
        else if(it)ok=dfs_iterativa(g,primeira,&r,rastro);
        else ok=dfs_matriz(matriz,n,primeira,&r);
        if(!ok)break;
    }
    clock_t b=clock();if(rastro)fclose(rastro);
    if(!ok){fprintf(stderr,"DFS falhou: confira implementacao, origem e alocacao.\n");resultado_libera(&r);free(matriz);grafo_lista_libera(g);return 5;}
    FILE *out=arquivo(argv[3],".vertices.csv"),*met=arquivo(argv[3],".metricas.csv"),*cam=arquivo(argv[3],".caminhos.csv");
    if(!out||!met||!cam){if(out)fclose(out);if(met)fclose(met);if(cam)fclose(cam);resultado_libera(&r);free(matriz);grafo_lista_libera(g);return 4;}
    fprintf(out,"vertice,estado,pai,descoberta,termino,componente,ordem_descoberta,ordem_termino\n");
    for(int v=0;v<n;++v){int od=-1,of=-1;
        for(int k=0;k<r.tam_d;++k)if(r.ordem_d[k]==v)od=k;
        for(int k=0;k<r.tam_f;++k)if(r.ordem_f[k]==v)of=k;
        fprintf(out,"%d,%d,%d,%d,%d,%d,%d,%d\n",v,r.estado[v],r.pai[v],r.d[v],r.f[v],r.componente[v],od,of);}
    fprintf(met,"modo,V,E,componentes,ciclo,exames,max_pilha,tempo_us\n");
    double us=(a==(clock_t)-1||b==(clock_t)-1)?-1.0:1e6*(double)(b-a)/CLOCKS_PER_SEC/repeticoes;
    fprintf(met,"%s,%d,%d,%d,%d,%lld,%d,%.6f\n",argv[2],n,m,r.componentes,r.tem_ciclo,r.exames,r.max_pilha,us);
    fprintf(cam,"destino,tamanho,caminho\n");
    int *vet=malloc((size_t)(n>0?n:1)*sizeof(int));if(!vet){fclose(out);fclose(met);fclose(cam);resultado_libera(&r);free(matriz);grafo_lista_libera(g);return 3;}
    int origem=primeira>=0?primeira:0;
    for(int v=0;v<n;++v){int tam=reconstroi_caminho(r.pai,n,origem,v,vet,n);
        fprintf(cam,"%d,%d,\"",v,tam);for(int j=0;j<tam;++j){if(j)fputc(';',cam);fprintf(cam,"%d",vet[j]);}fprintf(cam,"\"\n");}
    free(vet);fclose(out);fclose(met);fclose(cam);resultado_libera(&r);free(matriz);grafo_lista_libera(g);return 0;
}
