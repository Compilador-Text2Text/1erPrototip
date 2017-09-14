#include <stdlib.h>
#include <string.h>
#include "llegir-fitxer.h"

/**
  * Funció per inicialitzar la lectura.
  */
FILE *
inicialitzar_lectura_fitxer (char *nom)
{
	FILE *punter_fitxer = fopen (nom, "r");

	// Si hi ha algún problema.
	if (!punter_fitxer)
	{
		printf("El fitxer: %s\nNo existeix o no tenim permisos d'accés.\n", nom);
		exit(EXIT_FAILURE);
	}

	return punter_fitxer;
}

void
finalitzar_lectura_fitxer (FILE *punter_fitxer)
{
	if (punter_fitxer)
	{
		fclose (punter_fitxer);
		punter_fitxer = NULL;
	}
}

char
seguent_caracter (FILE *punter_fitxer)
{
	char c = fgetc (punter_fitxer);

	if ( c == EOF )
	{
		printf ("Error, s'ha cridat la funció següent caràcter quan aquest no té següent.\n");
		exit(EXIT_FAILURE);
	}

	return c;
}

int
seguenta_linia (FILE *punter_fitxer, int llargada, char *linia)
{
	char *e;

	if (fgets (linia, llargada, punter_fitxer))
	{
		e = memchr (linia, '\n', llargada);
		if (e)
			return 1;

		printf ("Error en lectura.\n");
		printf ("La llargada és insuficient, %d és insuficient.\n", llargada);
		printf ("Necessitem més caracters per a poder treballar adequadament.\n");
		exit (EXIT_FAILURE);
	}
	return 0;
}
