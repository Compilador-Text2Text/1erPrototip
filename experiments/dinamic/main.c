#include <stdio.h>
#include "vector.h"

// Totes les funcions de vector.h provades.
// Posant al límit el vector. "inicialitzat a zero".
int
main()
{
	int i = 0;
	struct vector v = vector_inicialitzar ( 0, sizeof(int) );

	// Guardar informació
	for (i = 0; i < 20; i+=3)
		vector_afegir (&v, &i);

	// Mostrat el que s'ha posat.
	for (i = 0; i < v.us; i++)
		printf ("Iteració: %2d Valor: %2d\n", i,
		*(int*)vector_retorn_element(&v,i));

	// Mostrar al reves.
	for (i = 0; i < v.us; i++)
		printf ("Reves: %2d Valor: %2d\n", i,
		*(int*)vector_retorn_element_reves(&v,i));

	// Modificar els valors.
	*(int*)vector_retorn_element(&v,0) = 500;
	i = 724;
	vector_modifica_element (&v, 3, &i);

	// Treure tot
	while (v.us)
		printf ("Extret: %d\n", *(int*)vector_treure (&v));

	// Eliminar la llista.
	vector_alliberar(&v);

	// Afegir un element. Per mostrar-lo.
	i = 27; vector_afegir (&v, &i);
	printf ("Extret 2: %d\n", *(int*)vector_treure (&v));

	// Eliminar la llista.
	vector_alliberar(&v);
return 0;
}
