#include "executor.h"
int estat;

int
funcio_executa_codi
	(
		struct funcio_estat punter_funcio_estat,
		struct pila_funcio_dinamica localitzacio_funcio_dinamica
	)
{
	while	(
			punter_funcio_estat
				(
					punter_funcio_estat,
					localitzacio_funcio_dinamica
				)
		);

	return estat; // !!! No sé que fer encara.
}
