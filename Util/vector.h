#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>

// estructura per tenir la llista.
struct
vector
{
	size_t us;
	size_t capacitat;
	size_t byts;
	void * dada;
};

/* Inicialitzar i finalitzar la llista */
struct vector vector_inicialitzar (size_t capacitat_inicial,
					size_t byts_per_element);
void vector_alliberar (struct vector *v);

/* Instruccions de pila */
void  vector_afegir (struct vector *v, void* dada);
void* vector_treure (struct vector *v);
void* vector_mostra (struct vector *v);

/* Instruccions de llista */
void* vector_retorn_element (struct vector *v, size_t i);
void* vector_retorn_element_reves (struct vector *v, size_t i);
void vector_modifica_element (struct vector *v, size_t i, void *dada);

/* Instrucció per modificar elements usats */
void vector_modifica_us (struct vector *v, size_t nou_us);

#endif // VECTOR_H_
