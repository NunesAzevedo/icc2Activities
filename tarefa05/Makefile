CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2

.PHONY: all basicas indexada salto interpolacao exponencial main clean

all:
	rm -f buscas
	gcc $(CFLAGS) basicas.c indexada.c salto.c interpolacao.c exponencial.c main.c -o buscas

basicas:
	gcc $(CFLAGS) -c basicas.c -o basicas.o

indexada:
	gcc $(CFLAGS) -c indexada.c -o indexada.o

salto:
	gcc $(CFLAGS) -c salto.c -o salto.o

interpolacao:
	gcc $(CFLAGS) -c interpolacao.c -o interpolacao.o

exponencial:
	gcc $(CFLAGS) -c exponencial.c -o exponencial.o

main:
	gcc $(CFLAGS) -c main.c -o main.o

clean:
	rm -f basicas.o indexada.o salto.o interpolacao.o exponencial.o main.o buscas
