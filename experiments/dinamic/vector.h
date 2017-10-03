#ifndef DEFINICIO_PER_EXECUCIO_H_
#define DEFINICIO_PER_EXECUCIO_H_

#include <stdlib.h>

// https://www.happybearsoftware.com/implementing-a-dynamic-array

// Descriu el vector
struct
vector
{
	size_t us;
	size_t capacitat;
	size_t byts;
	void * dada;
};

struct vector vector_inicialitzar (size_t capacitat, size_t byts);
void  vector_afegir (struct vector *v, void* dada);
void* vector_treure (struct vector *v);
void* vector_retorn_element (struct vector *v, size_t i);
void vector_modifica_element (struct vector *v, size_t i, void *dada);
void vector_alliberar (struct vector *v);

//void vector_set(Vector *vector, int index, int value);

#endif // DEFINICIO_PER_EXECUCIO_H_
