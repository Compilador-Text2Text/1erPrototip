#include <string.h>

#include "../Execució/executor.h"

// 0
int igual_general (size_t nombre_arguments, struct element_dExecucio *eex)
{
	*((union valor*)eex[0].punter) = eex[1].valor;
	return 1;
}

// 1
int extreu_punter (size_t na, struct element_dExecucio *e)
{
	e->valor.punter = e->punter;
	return 1;
}

// 2
int producte_enter (size_t na, struct element_dExecucio *e)
{
	e[0].valor.enter *= e[1].valor.enter;
	return 1;
}
// 3
int resta_enter (size_t na, struct element_dExecucio *e)
{
	e[0].valor.enter -= e[1].valor.enter;
	return 1;
}
// 4

void descriu_C_0 ()
{
	struct descriptor_funcio *dfm; // Descriptor de funció per modificar.
	struct variable *v;
	struct frase *f;
	struct paraula_codi *p;

	// Funcions de sistema
	llista_funcions_sistema = malloc (10 *
		sizeof (int (*)(size_t, struct element_dExecucio *)));
	llista_funcions_sistema[0] = igual_general;
	llista_funcions_sistema[1] = extreu_punter;
	llista_funcions_sistema[2] = producte_enter;
	llista_funcions_sistema[3] = resta_enter;

	// Variables globals
	variables_globals.mida		= 0;
	variables_globals.variables	= NULL;

	// Funcions general
	descriptors_funcio.capacitat	= 1;
	descriptors_funcio.descriptor	= malloc(1*
			sizeof(struct descriptor_funcio));

	// Primera funció
	/*
	 * int a, b = 3;
	 * int *p;
	 * p = &a;
	 * b = 3 * 7 -b;
	 * a = 2^b;
	 * return a;
	 */
	dfm = descriptors_funcio.descriptor;

	// Arguments
	dfm->arguments.mida		= 0;
	dfm->arguments.variables	= NULL;
	dfm->adicionals			= Cap;

	// Locals
	dfm->locals.mida		= 3;
	dfm->locals.variables		= malloc (3*sizeof(struct variable));
	v = dfm->locals.variables;
	v->nom = strdup ("a");
	v->descriptor.tipus = Int;
	v->descriptor.vegades_punter = 0;

	v = dfm->locals.variables +1;
	v->nom = strdup("b");
	v->valor.enter = 3;
	v->descriptor.tipus = Int;
	v->descriptor.vegades_punter = 0;

	v = dfm->locals.variables +2;
	v->nom = strdup("p");
	v->descriptor.tipus = Int;
	v->descriptor.vegades_punter = 1;

	// Codi
	dfm->longitud_maxima_frases = 7; // b = 3 * 7 -b;
	dfm->dimencio_memoria_dExecucio = 3;
	dfm->codi.mida = 5;
	dfm->codi.frase = malloc (5*sizeof(struct frase));

	// b = 3
	f = dfm->codi.frase;
	f->mida = 3;
	f->paraula = malloc (3*sizeof(struct paraula_codi));

	// b
	p = f->paraula; // b = 3;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 0;
	p->localitzacio_completa.quin_vector_es = Local;
	p->localitzacio_completa.lloc_relatiu = 1;

	// 3
	p = f->paraula +1;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 0;
	p->localitzacio_completa.quin_vector_es = Codi;
	p->auxiliar.enter = 3;

	// =
	p = f->paraula +2;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 0;
	p->localitzacio_completa.quin_vector_es = Sistema;
	p->localitzacio_completa.lloc_relatiu = 0;
	p->auxiliar.enter = 2;

	// p = &a
	f = dfm->codi.frase +1;
	f->mida = 4;
	f->paraula = malloc (4*sizeof(struct paraula_codi));

	// p
	p = f->paraula; // p = &a;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 1;
	p->localitzacio_completa.quin_vector_es = Local;
	p->localitzacio_completa.lloc_relatiu = 2;

	// a
	p = f->paraula +1;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 0;
	p->localitzacio_completa.quin_vector_es = Local;
	p->localitzacio_completa.lloc_relatiu = 0;

	// &
	p = f->paraula +2;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 1;
	p->localitzacio_completa.quin_vector_es = Sistema;
	p->localitzacio_completa.lloc_relatiu = 1;
	p->auxiliar.enter = 1;

	// =
	p = f->paraula +3;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 1;
	p->localitzacio_completa.quin_vector_es = Sistema;
	p->localitzacio_completa.lloc_relatiu = 0;
	p->auxiliar.enter = 2;

	// b = 3 * 7 -b
	f = dfm->codi.frase +2;
	f->mida = 7;
	f->paraula = malloc (7*sizeof(struct paraula_codi));

	// b
	p = f->paraula;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 0;
	p->localitzacio_completa.quin_vector_es = Local;
	p->localitzacio_completa.lloc_relatiu = 1;

	// 3
	p = f->paraula +1;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 0;
	p->localitzacio_completa.quin_vector_es = Codi;
	p->auxiliar.enter = 3;

	// 7
	p = f->paraula +2;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 0;
	p->localitzacio_completa.quin_vector_es = Codi;
	p->auxiliar.enter = 7;

	// *
	p = f->paraula +3;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 0;
	p->localitzacio_completa.quin_vector_es = Sistema;
	p->localitzacio_completa.lloc_relatiu = 2;
	p->auxiliar.enter = 2;

	// b
	p = f->paraula +4;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 0;
	p->localitzacio_completa.quin_vector_es = Local;
	p->localitzacio_completa.lloc_relatiu = 1;

	// -
	p = f->paraula +5;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 0;
	p->localitzacio_completa.quin_vector_es = Sistema;
	p->localitzacio_completa.lloc_relatiu = 3;
	p->auxiliar.enter = 2;

	// =
	p = f->paraula +6;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 1;
	p->localitzacio_completa.quin_vector_es = Sistema;
	p->localitzacio_completa.lloc_relatiu = 0;
	p->auxiliar.enter = 2;

	// a = 2^b
	f = dfm->codi.frase +3;
	f->mida = 5;
	f->paraula = malloc (5*sizeof(struct paraula_codi));

	// a
	p = f->paraula +0;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 0;
	p->localitzacio_completa.quin_vector_es = Local;
	p->localitzacio_completa.lloc_relatiu = 0;

	// 2
	p = f->paraula +1;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 0;
	p->localitzacio_completa.quin_vector_es = Codi;
	p->auxiliar.enter = 3;

	// b
	p = f->paraula +2;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 0;
	p->localitzacio_completa.quin_vector_es = Local;
	p->localitzacio_completa.lloc_relatiu = 1;

	// ^
	p = f->paraula +3;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 1;
	p->localitzacio_completa.quin_vector_es = Sistema;
	p->localitzacio_completa.lloc_relatiu = 4;
	p->auxiliar.enter = 2;

	// =
	p = f->paraula +4;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 1;
	p->localitzacio_completa.quin_vector_es = Sistema;
	p->localitzacio_completa.lloc_relatiu = 0;
	p->auxiliar.enter = 2;

	// return a
	f = dfm->codi.frase +4;
	f->mida = 2;
	f->paraula = malloc (2*sizeof(struct paraula_codi));
	p = f->paraula +0;
	p = f->paraula +1;

}
	/*
	struct descriptor_valor	descriptor;
	struct localitzacio	localitzacio_completa;
	union  valor		auxiliar;

	struct paraula_codi *paraula;
	size_t mida;
	 * int a, b = 3;
	 * int *p;
	 * p = &a;
	 * b = 3 * 7 -b;
	 * a = 2^b;
	 * return a;
	 */
