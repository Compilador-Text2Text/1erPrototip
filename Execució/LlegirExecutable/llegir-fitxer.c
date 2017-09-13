#include <stdlib.h>
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
	return fgetc (punter_fitxer);
}

int
seguenta_linia (FILE *punter_fitxer, int llargada, char *linia)
{
	if (fgets (linia, llargada, punter_fitxer))
		return 1;
	return 0;
}
