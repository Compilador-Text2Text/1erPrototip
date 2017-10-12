#include "executor.h"
int estat;
struct variables variables_globals;
struct llista_descriptors_funcio descriptors_funcio;

// !!! Llegir les dades de codi és crític.
// Vigilar sobretot amb els punters, de no modificar el contingut del codi.
void dades_codi (struct element_dExecucio *edE,
		struct paraula_codi paraula)
{
		edE->descriptor	= paraula.descriptor;
		edE->valor	= paraula.auxiliar;
		edE->punter	= NULL;
}
void dades_variables (struct element_dExecucio *edE, struct variable *var)
{
	edE->descriptor	= var->descriptor;
	edE->valor	= var->valor;
	edE->punter	= &var->valor;
}


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

struct element_dExecucio *
obtencio_lElement_dExecucio ( struct funcio_dinamica* fc)
{ return fc->memoria_dExecucio.memoria + fc->memoria_dExecucio.us++; }


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

	struct element_dExecucio	*edE;

	// Definim paraula.
	fc=(struct funcio_dinamica*) vector_mostra(pila_funcio_dinamica);
	paraula = toquen_i_increment (fc);

	edE = obtencio_lElement_dExecucio (fc);
	edE->localitzat	= paraula.localitzacio_completa;

	switch ( paraula.localitzacio_completa.quin_vector_es )
	{
	// Codi
	case Codi:
		dades_codi (edE, paraula);
		return 1;

	// Variables.
	case Arguments:
		dades_variables (edE, fc->arguments.variables +
			paraula.localitzacio_completa.lloc_relatiu);
		return 1;

	case Local:
		dades_variables (edE, fc->locals.variables +
			paraula.localitzacio_completa.lloc_relatiu);
		return 1;

	case Global:
		dades_variables (edE, variables_globals.variables +
			paraula.localitzacio_completa.lloc_relatiu);
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
