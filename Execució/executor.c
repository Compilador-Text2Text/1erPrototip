#include "executor.h"
int estat;
struct llista_variables_globals variables_globals;
struct llista_descriptors_funcio descriptors_funcio;


int
funcio_executa_codi
	(
		struct punter_funcio_estat *pfe,
		struct vector *pila_funcio_dinamica
	)
{
	while	(
			pfe->func
				(
					pfe,
					pila_funcio_dinamica
				)
		);

	return estat; // !!! No sé que fer encara.
}
