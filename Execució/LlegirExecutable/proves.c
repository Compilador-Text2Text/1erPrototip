#include <stdlib.h>
#include <string.h>
#include "llegir-fitxer.h"
/**
  * Codi per a veure com és comporta el fgets i fgetc
  */

// Aparentment funciona
void
test_fgetc (FILE *punter_fitxer)
{
	char c;
	while (!feof (punter_fitxer))
	{
		c = seguent_caracter (punter_fitxer);
		if (c != EOF)
			printf ("%c", c);
	}
}

void
test_fgets5 (FILE *punter_fitxer)
{
// PENDENT
	int size = 5;
	int bucle= 1;
	char *c = (char *) malloc (size * sizeof (char));

	while (bucle)
	{
		bucle = seguenta_linia (punter_fitxer, size, c);
		if (bucle)
			printf ("%s", c);
	}
}

void
test_fgets5Error (FILE *punter_fitxer)
{
// PENDENT
	int size = 5;
	int bucle= 1;
	char *c = (char *) malloc (size * sizeof (char));
	char *e;

	while (bucle)
	{
		bucle = seguenta_linia (punter_fitxer, size, c);
		if (bucle)
		{
			//e = strchr (c, '\n');
			e = memchr (c, '\n', size);
			if (!e)
				printf ("Error\n");
			printf ("|%s^%s|", c, e);
		}
	}
}

void
test_fgets300 (FILE *punter_fitxer)
{
// PENDENT
	int size = 300;
	int bucle= 1;
	char *c = (char *) malloc (size * sizeof (char));

	while (bucle)
	{
		bucle = seguenta_linia (punter_fitxer, size, c);
		if (bucle)
			printf ("%s", c);
	}
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
	case 'b': test_fgets5(punter_fitxer_assemblador); break;
	case 'c': test_fgets5Error(punter_fitxer_assemblador); break;
	case 'd': test_fgets300(punter_fitxer_assemblador); break;
	default:
		printf ("Agafi un valor vàlid pel segon paràmetre:\na\tfgetc\n");
		printf ("b\tfgets de 5\n");
		printf ("c\tfgets de 5 amb error\n");
		printf ("d\tfgets de 300\n");
	}
	finalitzar_lectura_fitxer (punter_fitxer_assemblador);
// EOF vs feof
// Pendent veure que passa quan poses un valor menor a la línia
	return 0;
}
