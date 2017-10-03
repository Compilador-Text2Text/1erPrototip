#include <stdio.h>
#include "vector.h"

// Totes les funcions de vector.h provades.
// Posant al límit el vector. "inicialitzat a zero".
int
main()
{
	int i = 0;
	struct vector v = vector_inicialitzar ( 0, sizeof(int) );

	for (i = 0; i < 20; i+=3)
		vector_afegir (&v, &i);

	for (i = 0; i < v.us; i++)
		printf ("Iteració: %2d Valor: %2d\n", i,
		*(int*)vector_retorn_element(&v,i));

	*(int*)vector_retorn_element(&v,0) = 500;
	i = 724;
	vector_modifica_element (&v, 3, &i);

	while (v.us)
		printf ("Extret: %d\n", *(int*)vector_treure (&v));

	free(v.dada);
return 0;
}
