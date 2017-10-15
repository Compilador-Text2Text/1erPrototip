CFLAGS=-Wall -g

executor.o: executor.c executor.h ../Util/vector.h Makefile
	gcc executor.c $(CFLAGS) -c

h: definicio.h.gch
definicio.h.gch: definicio.h
	gcc definicio.h -Wall
clean:
	rm executor.o definicio.h.gch
