#include <stdlib.h>
#include <ctype.h>

#include "llegir-fitxer.h"
#include "analitzador-sintactic.h"

int
busca_enter (FILE *punter_fitxer)
{
	char c;
	int bolea = 1, retorn = 0;

	// busquem
	while ( bolea )
	{
		switch ( (c = seguent_caracter (punter_fitxer)) )
		{
		case '#': while ( (c = seguent_caracter (punter_fitxer)) != '\n' ); break;
		case '\n': break;
		case '\t': break;
		case ' ': break;
		default: bolea = 0;
		}
	}

	// Transformem char a int
	while (isdigit (c))
	{
		retorn = 10*retorn + c -'0';
		c = seguent_caracter (punter_fitxer);
	}

	return retorn;
}
