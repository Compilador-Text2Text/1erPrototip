#include "executor.h"
int estat;
struct variables variables_globals;
struct llista_descriptors_funcio descriptors_funcio;

// !!! Llegir les dades de codi és crític.


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

struct paraula_codi toquen_i_increment ( struct funcio_dinamica *fc )
;

/*/ estructura per tenir la llista.
struct
vector
{
	size_t us;
	size_t capacitat;
	size_t byts;
	void * dada;
};*/
int
execucio_paraula ( struct vector *pila_funcio_dinamica )
{
	struct paraula_codi		paraula;
	struct funcio_dinamica		*fc;

	struct memoria_dExecucio	mdE;
	struct element_dExecucio	*edE;
	struct variable			*var;

	// Definim paraula.
	fc=(struct funcio_dinamica*) vector_mostra(pila_funcio_dinamica);
	paraula = toquen_i_increment (fc);

	// Obtenim l'element d'Execució.
	mdE = fc->memoria_dExecucio;
	edE = mdE.memoria + mdE.us;
	edE->localitzat	= paraula.localitzacio_completa;
	fc->memoria_dExecucio.us++;

	switch ( paraula.localitzacio_completa.quin_vector_es )
	{
	// Codi
	// !!! Crític, fer que edE->valor = paraula.auxiliar (punters)
	case Codi:
		// Dades estan a l'auxiliar de la paraula.
		edE->descriptor	= paraula.descriptor;
		edE->valor	= paraula.auxiliar;
		edE->punter	= NULL;

		return 1;

	// Variables.
	case Arguments:
		*edE = *(fc->memoria_dExecucio_dArguments +
			paraula.localitzacio_completa.lloc_relatiu);
		edE->localitzat = paraula.localitzacio_completa;

		return 1;

	case Local:
		var = fc->locals.variables +
			paraula.localitzacio_completa.lloc_relatiu;

		edE->descriptor	= var->descriptor;
		edE->valor	= var->valor;
		edE->punter	= &var->valor;

		return 1;

	case Global:
		var = variables_globals.variables +
			paraula.localitzacio_completa.lloc_relatiu;

		edE->descriptor	= var->descriptor;
		edE->valor	= var->valor;
		edE->punter	= &var->valor;

		return 1;

	// Funcions.
	case Funcio:
	case Sistema:
	return 1;
	default:
	return 0;
	}
return 0;
}
