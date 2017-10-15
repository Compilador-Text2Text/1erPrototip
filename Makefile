ALL_OBJ=main.o					\
	Inicialitzadors/inicialitzador_C.o	\
	Execució/executor.o			\
	Util/vector.o				\
	Descriu/descriu_C_0.o
CFLAGS=-Wall -g

main: $(ALL_OBJ) Makefile
	gcc $(ALL_OBJ) $(CFLAGS) -o main

main.o: main.c Makefile
	gcc main.c $(CFLAGS) -c

Inicialitzadors/inicialitzador_C.o: Inicialitzadors/inicialitzador_C.c
	cd Inicialitzadors; make inicialitzador_C.o

Execució/executor.o: Execució/executor.c
	cd Execució; make executor.o

Util/vector.o: Util/vector.c
	cd Util; make vector.o

Descriu/descriu_C_0.o: Descriu/descriu_C_0.c
	cd Descriu; make descriu_C_0.o

clean:
	rm $(ALL_OBJ) main -f
