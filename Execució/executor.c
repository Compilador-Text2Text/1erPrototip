#include <string.h>

#include "executor.h"

int estat;
struct variables variables_globals;
struct llista_descriptors_funcio descriptors_funcio;
int (**llista_funcions_sistema) (size_t , struct element_dExecucio *);

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

void funcions_generacio
(
 size_t nombre_arguments,
 struct element_dExecucio *eex,
 size_t relatiu_descriptor_funcio,
 struct vector *pila_funcio_dinamica
)
{
	size_t i;
	struct funcio_dinamica fd;

	// Execució.
	fd.fila = 0; fd.columna = 0;
	fd.descriptor = descriptors_funcio.descriptor +
			relatiu_descriptor_funcio;
	fd.memoria_dExecucio.capacitat =
		fd.descriptor->dimencio_memoria_dExecucio;
	fd.memoria_dExecucio.us = 0;
	fd.memoria_dExecucio.memoria = (struct element_dExecucio*) malloc
		(fd.descriptor->dimencio_memoria_dExecucio *
		 sizeof (struct element_dExecucio));

	// Arguments.
	eex -= nombre_arguments;
	fd.memoria_dExecucio_dArguments = eex; // Retorn
	fd.arguments.mida = nombre_arguments;
	fd.arguments.variables = (struct variable*) malloc
		(nombre_arguments * (sizeof (struct variable)));
	for (i = 0; i < nombre_arguments; i++)
		dades_variables (eex +i, fd.arguments.variables +i);

	// Variables locals.
	fd.locals = fd.descriptor->locals;
	fd.locals.variables = (struct variable*) malloc (fd.locals.mida *
			sizeof (struct variable));
	memcpy (fd.locals.variables, fd.descriptor->locals.variables,
			fd.locals.mida * sizeof (struct variable));

	// Ho posa a la pila
	vector_afegir (pila_funcio_dinamica, &fd);
}

int funcions_sistema
(
 size_t nombre_arguments,
 struct element_dExecucio *eex,
 size_t relatiu_sistema_funcio
)
{
	return llista_funcions_sistema[relatiu_sistema_funcio] (nombre_arguments, eex -nombre_arguments);
}
int execucio_paraula ( struct vector *pila_funcio_dinamica );
int funcio_executa_paraula (struct punter_funcio_estat *,struct vector *);
// !!! Aquest aquí no m'agrada.
// El voldria més aviat a la carpeta inicialitzar...
int
inicialitzador_i_execucio_C
	(
		enum pilar_dExecucio	execucio, // Saber com executar.
		int			nombre_arguments,
		char **			vector_arguments
	)
{
	struct punter_funcio_estat pfe;
	struct vector pila_funcio_dinamica;

	// Definint la funció d'execució.
	switch ( execucio )
	{
	case Defecte: pfe.func = funcio_executa_paraula; break;
	default: exit (3);
	}

	// Definint la pila de funció dinàmica.
	pila_funcio_dinamica = vector_inicialitzar (30, sizeof
			(struct funcio_dinamica));

	funcions_generacio (0, NULL, 0, &pila_funcio_dinamica);

	funcio_executa_codi (&pfe, &pila_funcio_dinamica);
	return 0;
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

int funcio_executa_paraula
(
 struct punter_funcio_estat *pfe,
 struct vector *pila_funcio_dinamica
)
{ return execucio_paraula (pila_funcio_dinamica); }


struct paraula_codi toquen_i_increment ( struct funcio_dinamica *fc )
{
	struct paraula_codi paraula =
		fc->descriptor->codi.frase[fc->fila].paraula[fc->columna];

	if ( fc->columna +1 == fc->descriptor->codi.frase[fc->fila].mida )
	{
		// !!!
		// Tocaria alliberar la memoria d'execució
		fc->memoria_dExecucio.us = 0;
		fc->columna = 0;
		fc->fila++;
	} else
		fc->columna++;

	return paraula;
}

struct element_dExecucio *
obtencio_lElement_dExecucio ( struct funcio_dinamica* fc)
{ return fc->memoria_dExecucio.memoria + fc->memoria_dExecucio.us++; }

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
		fc->memoria_dExecucio.us -= paraula.auxiliar.enter;
		funcions_generacio (paraula.auxiliar.enter, edE,
			paraula.localitzacio_completa.lloc_relatiu,
			pila_funcio_dinamica);
		return 1;

	case Sistema:
		fc->memoria_dExecucio.us -= paraula.auxiliar.enter;
		return funcions_sistema (paraula.auxiliar.enter, edE,
			paraula.localitzacio_completa.lloc_relatiu);
	case Retorn:
	return 1;
	default:
	return 0;
	}
return 0;
}
