CFLAGS=-Wall -g

NOM=vector

../Bin/$(NOM).o: $(NOM).c $(NOM).h Makefile
	gcc $(NOM).c $(CFLAGS) -c -o ../Bin/$(NOM).o

test: test.exe

test.exe: test_memoria_dinamica.c vector.c vector.h
	gcc vector.c test_memoria_dinamica.c -Wall -g -o test.exe
