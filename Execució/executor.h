#ifndef EXECUTOR_H_
#define EXECUTOR_H_

#include "definicio.h"
#include "../Util/vector.h"

// !!! Definir: Llistes i pila. Pensa com fer-ho!!
// Variables Globals.
extern struct llista_variables_globals
{
	size_t capacitat;
	struct variable variables;
} variables_globals;

// Descriptor de funció.
extern struct llista_descriptors_funcio
{
	size_t capacitat;
	struct descriptor_funcio descriptor;
} descriptors_funcio;

// Funcio estat
struct punter_funcio_estat
{
	int (*func) (struct punter_funcio_estat*,
		struct vector *pila_funcio_dinamica);
};

#endif // EXECUTOR_H_
