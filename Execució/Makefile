executor.o: executor.c executor.h ../Util/vector.h
	gcc executor.c -Wall -g -c

h: definicio.h.gch
definicio.h.gch: definicio.h
	gcc definicio.h -Wall
clean:
	rm executor.o
