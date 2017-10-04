// Comprovar els prints siguin vàlids i correctes.
#include <string.h>
#include <stdio.h>
#include "vector.h"

int main ()
{
	size_t capacitat = 1, byts =2, i = 3;
	struct vector a={
			.us		= 0,
			.capacitat	= capacitat,
			.byts		= byts,
			.dada		= malloc (capacitat*byts)
			};
	struct vector *v = &a;

	printf ("-- vector_inicialitzar --\n");
	printf ("%s\nCapacitat: %zu, Nombre de byts: %zu\n%s\n",
	"Error al inicialitzar el vector.", capacitat, byts,
	"Error generat pel malloc!");

printf ("\n\n");

	printf ("-- incrementar_capacitat_del_vector --\n");
	printf ("%s\nCapacitat: %zu, Nombre de byts: %zu\n%s\n",
	"Error al redefinir la capacitat del vector.", v->capacitat, v->byts,
	"Error generat pel realloc!");

printf ("\n\n");

	printf ("-- vector_treure --\n");
	printf ("%s\n%s%zu\n%s\n",
	"Error al treure un element.",
	"Element restants: ", v->us,
	"Error generat al treure on no queda res."
	);

printf ("\n\n");

	printf ("-- vector_retorn_element --\n");
	printf ("-- vector_retorn_element_reves --\n");
	printf ("-- vector_modifica_element --\n");
	printf ("%s\n%s%zu, %s%zu\n%s\n",
	"Error al retornar un element.",
	"Elements usats: ", v->us,
	"Element demanat ", i,
	"Error generat al demanar un element fora de lloc"
	);
return 0;
}
