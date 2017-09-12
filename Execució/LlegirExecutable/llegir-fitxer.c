#include <stdlib.h>
#include <stdio.h>

// Necessitem obrir el codi `assemblador'
FILE *punter_fitxer_assemblador;

/**
  * Funció per inicialitzar la lectura.
  */
void inicialitzar_lectura_fitxer (char *nom)
{
	punter_fitxer_assemblador = fopen (nom, "r");

	// Si hi ha algún problema.
	if (!punter_fitxer_assemblador)
	{
		printf("El fitxer: %s\nNo existeix o no tenim permisos d'accés.\n", nom);
		exit(EXIT_FAILURE);
	}
}

void finalitzar_lectura_fitxer ()
{
	if (punter_fitxer_assemblador)
	{
		fclose (punter_fitxer_assemblador);
		punter_fitxer_assemblador = NULL;
	}
}

char seguent_caracter ()
{
	return fgetc (punter_fitxer_assemblador);
}

int seguenta_linia (int llargada, char *linia)
{
	if (fgets (linia, llargada, punter_fitxer_assemblador)
		return 1;
	return 0;
}
