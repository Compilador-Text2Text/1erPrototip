ALL_OBJ=Bin/main.o				\
	Bin/inicialitzador_C.o			\
	Bin/executor.o				\
	Bin/vector.o				\
	Bin/descriu_C_0.o			\

CFLAGS=-Wall -g	\
       -l m	\

NOM=main

Bin/$(NOM): Bin $(ALL_OBJ) Makefile
	gcc $(ALL_OBJ) $(CFLAGS) -o Bin/$(NOM)

Bin/$(NOM).o: $(NOM).c Makefile
	gcc $(NOM).c $(CFLAGS) -c -o Bin/$(NOM).o

Bin/inicialitzador_C.o: Inicialitzadors/inicialitzador_C.c
	cd Inicialitzadors; make ../Bin/inicialitzador_C.o

Bin/executor.o: Execució/executor.c
	cd Execució; make ../Bin/executor.o

Bin/vector.o: Util/vector.c
	cd Util; make ../Bin/vector.o

Bin/descriu_C_0.o: Descriu/descriu_C_0.c
	cd Descriu; make ../Bin/descriu_C_0.o

Bin:
	mkdir Bin

clean:
	rm Bin/* -rf

.PHONY: clean
