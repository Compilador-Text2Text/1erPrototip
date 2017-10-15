CFLAGS=-Wall -g

vector.o: vector.c  vector.h
	gcc vector.c $(CFLAGS) -c

test: test.exe

test.exe: test_memoria_dinamica.c vector.c vector.h
	gcc vector.c test_memoria_dinamica.c -Wall -g -o test.exe
