#include <string.h>
#include <stdio.h>
#include "vector.h"

// memcpy
// https://www.tutorialspoint.com/c_standard_library/c_function_memcpy.htm
// http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/6-b14/java/util/ArrayList.java


struct vector vector_inicialitzar (size_t capacitat, size_t byts)
{
	struct vector v={
			.us		= 0,
			.capacitat	= capacitat,
			.byts		= byts,
			.dada		= malloc (capacitat*byts)
			};
	// Error
	if (!v.dada && (v.capacitat != 0))
	{
		printf ("%s\nCapacitat: %zu, Nombre de byts: %zu\n%s\n",
		"Error al inicialitzar el vector.", capacitat, byts,
		"Error generat pel malloc!");
		exit (EXIT_FAILURE);
	}
	return v;
}

void incrementar_capacitat_del_vector (struct vector *v)
{
	v->capacitat = (v->us * 3)/2 +1;
	v->dada = realloc (v->dada, v->capacitat * v->byts);

	// Error
	if (!v->dada)
	{
		printf ("%s\nCapacitat: %zu, Nombre de byts: %zu\n%s\n",
		"Error al redefinir la capacitat del vector.", v->capacitat, v->byts,
		"Error generat pel realloc!");
		exit (EXIT_FAILURE);
	}
}

// http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/6-b14/java/util/ArrayList.java
// public void ensureCapacity(int minCapacity)
// int newCapacity = (oldCapacity * 3)/2 + 1;

// Casos extrems, capacitat 0→1, 1→2, 2→4. Com més grans segur que no donen problemes.
void vector_afegir (struct vector *v, void* dada)
{
	// Cas en que no hi hagi més capacitat.
	if (v->us == v->capacitat)
		incrementar_capacitat_del_vector (v);

	// Emmagatzemem la informació.
	memcpy (v->dada + v->us++*v->byts, dada, v->byts);
}

void* vector_treure (struct vector *v)
{
	// Error
	if (v->us < 1)
	{
		printf ("%s\n%s%zu\n%s\n",
		"Error al treure un element.",
		"Element restants: ", v->us,
		"Error generat al treure on no queda res."
		);

		exit (EXIT_FAILURE);
	}

	return v->dada + (--v->us)*(v->byts);
}

void* vector_retorn_element (struct vector *v, size_t i)
{
	// Errors
	if ( i >= v->us )
	{
		printf ("%s\n%s%zu, %s%zu\n%s\n",
		"Error al retornar un element.",
		"Elements usats: ", v->us,
		"Element demanat ", i,
		"Error generat al demanar un element fora de lloc"
		);

		exit (EXIT_FAILURE);
	}

	// On està emmagatzemat.
	return v->dada + i*v->byts;
}

void vector_modifica_element (struct vector *v, size_t i, void *dada)
{ memcpy (vector_retorn_element(v,i), dada, v->byts); }

void vector_alliberar (struct vector *v)
{
	// Alliberem evitant errors.
	if (v->capacitat)
		free (v->dada);

	// Actualitzem els valors.
	v->us		= 0;
	v->capacitat	= 0;
	v->dada		= NULL;
}
