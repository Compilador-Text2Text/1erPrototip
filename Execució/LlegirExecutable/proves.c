#include "llegir-fitxer.h"
/**
  * Codi per a veure com és comporta el fgets i fgetc
  */

// Aparentment funciona
void
test_fgetc (FILE *punter_fitxer)
{
	while (!feof(punter_fitxer))
		printf ("%c", seguent_caracter (punter_fitxer));
}

void
test_fgets10 (FILE *punter_fitxer)
{
// PENDENT
	int size = 10;
	char *c = (char *) malloc (size * sizeof (char));
	 seguenta_linia (FILE *punter_fitxer, int llargada, char *linia);
}

int
main (int argc, char *argv[])
{
	// Necessitem obrir el codi `assemblador'
	FILE *punter_fitxer_assemblador;

	if (argc != 3)
	{
		printf ("Necessitem 2 arguments.\n");
		printf ("1er, el fitxer\n2n a fgetc\n");
		return 1;
	}

	// Crida principal
	punter_fitxer_assemblador = inicialitzar_lectura_fitxer (argv[1]);
	switch (*argv[2])
	{
	case 'a': test_fgetc (punter_fitxer_assemblador); break;
	default:
		printf ("Agafi un valor vàlid pel segon paràmetre:\na\tfgetc\n");
	}
	finalitzar_lectura_fitxer (punter_fitxer_assemblador);
// EOF vs feof
// Pendent veure que passa quan poses un valor menor a la línia
	return 0;
}
