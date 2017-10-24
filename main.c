#include <stdio.h>
#include <stdlib.h>

#include "definicio.h"
#include "Inicialitzadors/inicialitzador_C.h"
#include "Execució/executor.h"

#define Mostra_ajuda_error_tipus_dExecucio 1

void mostra_ajuda (int estat)
{
	switch (estat)
	{
	case Mostra_ajuda_error_tipus_dExecucio:
		printf ("Error, mal configurat el tipus d'execució.\n");
		break;
	}

	printf ("Formes de fer anar els arguments:\n\
\t-h	Mostra aquest missatge i surt.\n\
\t	Si té especificacions, donarà més informació al respecte.\n\
\t-a	[nombre d'arguments]	arguments separats per espais\n\
\t-pe	[defecte,depuració_de_programa]\n\
\t-i	[c]	[1]\n\
\n\
Exemples:\n\
\t-h -a\n\
\t-a 2 23 45 -pe defecte -i c 0\n\
\n\
Valors per defecte:\n\
	-a 0 -pe defecte -i c 0\n\
");

	if (estat)
		exit (1);
}

int main (int argc, char *argv[])
{
	// -a
	int nombre_arguments = 0;
	char **vector_arguments = NULL;

	// -pe
	enum pilar_dExecucio execucio = Defecte;

	// -i
	enum tipus_dExecucio tipus_memoria_execucio = C;
	size_t relatiu_dExecucio =0;

	switch (tipus_memoria_execucio)
	{
	case C:
		inicialitzador_C (relatiu_dExecucio);
		return inicialitzador_i_execucio_C (execucio, nombre_arguments,
				vector_arguments);

	default:
		mostra_ajuda (Mostra_ajuda_error_tipus_dExecucio);
		return 1;
	}
	return 0;
}
