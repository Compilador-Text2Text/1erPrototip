#include <string.h>

#include "../Execució/executor.h"

void descriu_C_0 ()
{
	struct descriptor_funcio *dfm; // Descriptor de funció per modificar.
	struct variable *v;
	struct frase *f;
	struct paraula_codi *p;

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
	dfm->arguments.mida		= 0;
	dfm->arguments.variables	= NULL;
	dfm->adicionals			= Cap;
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
	dfm->longitud_maxima_frases = 7; // b = 3 * 7 -b;
	dfm->dimencio_memoria_dExecucio = 3;
	dfm->codi.mida = 5;
	dfm->codi.frase = malloc (5*sizeof(struct frase));
	f = dfm->codi.frase;
	f->mida = 3;
	f->paraula = malloc (3*sizeof(struct paraula_codi));
	p = f->paraula; // b = 3;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 0;
	p->localitzacio_completa.quin_vector_es = Local;
	p->localitzacio_completa.lloc_relatiu = 1;
	p = f->paraula +1;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 0;
	p->localitzacio_completa.quin_vector_es = Codi;
	p->auxiliar.enter = 3;
	p = f->paraula +2;
	p->descriptor.tipus = Int;
	p->descriptor.vegades_punter = 0;
	p->localitzacio_completa.quin_vector_es = Sistema;
	p->localitzacio_completa.lloc_relatiu = 0;
	p->auxiliar.enter = 2;
	f = dfm->codi.frase +1;
	f->mida = 4;
	f->paraula = malloc (4*sizeof(struct paraula_codi));
	p = f->paraula; // p = &a;
	p = f->paraula +1;
	p = f->paraula +2;
	p = f->paraula +3;
	f = dfm->codi.frase +2;
	f = dfm->codi.frase +3;
	f = dfm->codi.frase +4;

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
