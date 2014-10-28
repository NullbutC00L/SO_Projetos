main: escritor fork_1

escritor: escritor.o
	gcc -o escritor escritor.o

fork_1: fork_1.o
	gcc -o fork_1 fork_1.o

escritor.o: escritor.c 
	gcc -g -c escritor.c

fork_1.o: fork_1.c
	gcc -g -c fork_1.c

