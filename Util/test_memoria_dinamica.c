#include <stdio.h>
#include "vector.h"

int
main ()
{
	int i = 0;
	struct vector v = vector_inicialitzar ( 30, sizeof(int) );
	vector_alliberar (&v);

	/*	Instruccions pila comprovació	*/
	printf ("Instruccions pila, fent la comprovació\n");

	// Guardar informació
	printf ("Provant afegir i mostrar l'element actual\n");
	for (i = 0; i < 70; i+=11)
	{
		vector_afegir (&v, &i);
		printf ("Actual: %2d\n", *(int*)vector_mostra (&v));
	}

	// Treure tot
	printf ("\nProvant eliminar correctament la informació\n");
	while (v.us)
		printf ("Extret: %d\n", *(int*)vector_treure (&v));

	/*	Instruccions llista	*/
	printf ("\nInstruccions llista\n");
	for (i = 0; i < 100; i = i*i +1)
		vector_afegir (&v, &i);

	// Mostrat el que s'ha posat.
	printf ("\nAmb índex\n");
	for (i = 0; i < v.us; i++)
		printf ("Iteració: %2d Valor: %2d\n", i,
		*(int*)vector_retorn_element(&v,i));

	// Mostrar al reves.
	printf ("\nAmb índex al revés\n");
	for (i = 0; i < v.us; i++)
		printf ("Reves: %2d Valor: %2d\n", i,
		*(int*)vector_retorn_element_reves(&v,i));

	// Modificació sense nous elements.
	printf ("\nModificació reciclant 'Amb índex al revés'\n");
	for (i = 0; i < v.us; i++)
		*(int*)vector_retorn_element_reves(&v,i) = i;
	for (i = 0; i < v.us; i++)
		printf ("Iteració: %2d Valor: %2d\n", i,
		*(int*)vector_retorn_element(&v,i));

	// Modificació amb la funció per modificar
	printf ("\nModificació amb la funció per a modificar\n");
	for (i = 0; i < v.us; i++)
		vector_modifica_element (&v, i, &i);
	for (i = 0; i < v.us; i++)
		printf ("Iteració: %2d Valor: %2d\n", i,
		*(int*)vector_retorn_element(&v,i));

	// Canvi de la dimensió a voluntat
	printf ("\nExemple canvi d'ús\n");
	vector_modifica_us (&v, 30);
	for (i = 0; i < v.us; i++)
		vector_modifica_element (&v, i, &i);
	for (i = 0; i < v.us; i++)
		printf ("Iteració: %2d Valor: %2d\n", i,
		*(int*)vector_retorn_element(&v,i));

	// Eliminar la llista.
	vector_alliberar(&v);
return 0;
}
