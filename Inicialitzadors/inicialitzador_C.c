#include <stdio.h>

#include "inicialitzador_C.h"
#include "../Execució/executor.h"
#include "../Descriu/descriu_C_0.h"

int inicialitzador_C
	(
		size_t			relatiu_dExecucio,
		enum pilar_dExecucio	execucio,
		size_t			nombre_arguments,
		char **			vector_arguments
	)
{
	struct punter_funcio_estat pfe;

	switch ( relatiu_dExecucio )
	{
	case 0: descriu_C_0 (); break;
	default:
		printf ("Error inicialitzador_C, no existeix tal funció\n");
	}

	// Definint la funció d'execució.
	switch ( execucio )
	{
	case Defecte: pfe.func = funcio_executa_codi; break;
	default:
		printf ("Error inicialitzador_C, agafat un paràmetre erroni\n");
		exit (1);
	}
int funcio_executa_codi ( struct punter_funcio_estat *, struct vector *);
	return 1;
}
