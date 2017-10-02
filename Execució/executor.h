#ifndef EXECUTOR_H_
#define EXECUTOR_H_

#include "definicio.h"

// !!! Definir: Llistes i pila. Pensa com fer-ho!!
// Variables Globals.
extern
struct
llista_variables_globals
variables_globals;

// Descriptor de funció.
extern
struct
llista_descriptors_funcio
descriptors_funcio;

// Funcio estat
struct funcio_estat
{
	int (*funcio)
		(
			struct funcio_estat,
			struct pila_funcio_dinamica
		);
};

#endif // EXECUTOR_H_
