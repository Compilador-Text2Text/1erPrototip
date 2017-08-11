experiment: os_pipe.py es_pipe.c
	#pkg-config --libs --cflags python3
	#gcc $(pkg-config --libs --cflags python3) es_pipe.c -o is
	gcc -I/usr/include/python3.6m -lpython3.6m es_pipe.c -o is
os_pipe: es_pipe.c
	cython3 os_pipe.py -o es_pipe.c
