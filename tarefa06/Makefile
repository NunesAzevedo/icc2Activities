CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2

.PHONY: all clean

all: teste_fila teste_grafo teste_bfs exporta_bfs teste_caminho marcacao_tardia \
     teste_componentes teste_bfs_matriz benchmark_bfs teste_ciclo graus_separacao

teste_fila:
	gcc $(CFLAGS) fila.c teste_fila.c -o teste_fila

teste_grafo:
	gcc $(CFLAGS) grafo_lista.c teste_grafo.c -o teste_grafo

teste_bfs:
	gcc $(CFLAGS) fila.c grafo_lista.c bfs.c teste_bfs.c -o teste_bfs

exporta_bfs:
	gcc $(CFLAGS) fila.c grafo_lista.c bfs.c exporta_bfs.c -o exporta_bfs

teste_caminho:
	gcc $(CFLAGS) fila.c grafo_lista.c bfs.c caminho.c teste_caminho.c -o teste_caminho

marcacao_tardia:
	gcc $(CFLAGS) fila.c grafo_lista.c marcacao_tardia.c -o marcacao_tardia

teste_componentes:
	gcc $(CFLAGS) fila.c grafo_lista.c componentes.c teste_componentes.c -o teste_componentes

teste_bfs_matriz:
	gcc $(CFLAGS) fila.c grafo_matriz.c bfs_matriz.c teste_bfs_matriz.c -o teste_bfs_matriz

benchmark_bfs:
	gcc $(CFLAGS) fila.c grafo_lista.c grafo_matriz.c benchmark_bfs.c -o benchmark_bfs

teste_ciclo:
	gcc $(CFLAGS) fila.c grafo_lista.c ciclo_bfs.c teste_ciclo.c -o teste_ciclo

graus_separacao:
	gcc $(CFLAGS) fila.c grafo_lista.c bfs.c caminho.c graus_separacao.c -o graus_separacao

clean:
	rm -f teste_fila teste_grafo teste_bfs exporta_bfs teste_caminho marcacao_tardia \
	      teste_componentes teste_bfs_matriz benchmark_bfs teste_ciclo graus_separacao \
	      resultado_bfs.csv benchmark_bfs.csv graus_separacao.csv
