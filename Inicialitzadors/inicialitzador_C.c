#include <stdio.h>

#include "inicialitzador_C.h"
#include "../Execució/executor.h"
#include "../Descriu/descriu_C_0.h"

int inicialitzador_C ( size_t relatiu_dExecucio)
{
	// Defineix les variables per l'execució.
	switch ( relatiu_dExecucio )
	{
	case 0: descriu_C_0 (); break;
	default:
		printf ("Error inicialitzador_C, no existeix tal funció\n");
		exit (1);
	}

	return 1;
}
