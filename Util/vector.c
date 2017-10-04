#include <string.h>
#include <stdio.h>
#include "vector.h"

/**
 *
 * Índex
 *
 * 1	Inicialitzar i finalitzar
 * 1.1		-inicialitzar 		Genera i crea l'estructura
 * 1.2		alliberar		Allibera l'estructura
 *
 * 2	Treball com si fos una pila
 * 2.1		>incrementar		Afegeix capacitat a la llista
 * 2.2		>memòria mínima		Assegura que quedin elements
 * 2.3		-afegir			Permet afegir un element
 * 2.4		-treure			Permet treure un element
 * 2.5		-mostra			Mostra l'últim element
 *
 * 3	Treball com si fos una llista
 * 3.0		>cercar			Assegura que sigui vàlid
 * 3.1		-indexat		Recuperem l'element indicat
 * 3.2		-indexat invers		Recuperem l'element indicat
 * 3.3		-modifica		Edita l'element indicat
 * 3.4		-modifica dimensió	Canvia el us sense afegir dades
 *
 **/

	/*1*	Poder Inicialitzar i finalitzar l'estructura	**/
/* Totes les dades necessàries per a poder generar l'estructura */
// Són llistes d'ús general.
// Pots emmagatzemar el que vulguis.
// Tot i que sempre guardarà el mateix nombre de byts.

/*1.1*		-inicialitzar 		Genera i crea l'estructura	**/
/* Crear l'inici de la instància, ja que traballa amb malloc */
// Un cop inicialitzat pots fer anar les altre operacions amb coherència.
// En cas de no poder-ho fer, destrozarà directament el programa "exit".
struct vector vector_inicialitzar (size_t capacitat, size_t byts)
{
	// Inicialitza l'estructura amb els valors corresponents.
	struct vector v={
			.us		= 0,
			.capacitat	= capacitat,
			.byts		= byts,
			.dada		= malloc (capacitat*byts)
			};

	// Evita que el programa continui en cas d'error.
	if (!v.dada && (v.capacitat != 0))
	{
		printf ("%s\nCapacitat: %zu, Nombre de byts: %zu\n%s\n",
		"Error al inicialitzar el vector.", capacitat, byts,
		"Error generat pel malloc!");
		exit (EXIT_FAILURE);
	}
	return v;
}

/*1.2*		alliberar		Allibera l'estructura		**/
/* Allibera la memoria i actualitza els valors */
// Permet continuar usant les funcions tenint en compte que ara
// la llista està completament buida.
void vector_alliberar (struct vector *v)
{
	// Alliberem evitant errors.
	if (v->capacitat)
		free (v->dada);

	// Actualitzem els valors.
	v->us		= 0;
	v->capacitat	= 0;
	v->dada		= NULL;
}

	/*2*	Treballar com si fos una pila				**/
/* Totes les operacions que podriem demanar a una pila */
// Afegir element, mirar o treure un element.

/*2.1*		>incrementar		Afegeix capacitat a la llista	**/
/* Incrementa la capacitat total, perquè l'ús pugui incrementar */
// En cas de no poder-ho fer, destrozarà directament el programa "exit".
// Testeixat, 0→1, 1→2 i sempre incrementa o iguala la diferència amb
// l'anterior, cosa que permet assegurar que realment incrementa.
void incrementar_capacitat_del_vector_en_necessitat (struct vector *v)
{
	// No cal fer res.
	if (v->us < v->capacitat) return;

	// Valor extret de open source de ArrayList de Java.
	v->capacitat = (v->capacitat * 3)/2 +1;

	// Assegura tamany mínim.
	if (v->capacitat <= v->us)
		v->capacitat = v->us +1;

	v->dada = realloc (v->dada, v->capacitat * v->byts);

	// Parem en cas d'error.
	if (!v->dada)
	{
		printf ("%s\nCapacitat: %zu, Nombre de byts: %zu\n%s\n",
		"Error al redefinir la capacitat del vector.", v->capacitat,
		v->byts, "Error generat pel realloc!");
		exit (EXIT_FAILURE);
	}
}

/*2.2*		>memòria mínima		Assegura que quedin elements	**/
/* Assegura que hi ha un element per poder treballar */
// En cas de no poder-ho assegurar-ho, sortirà amb "exit".
void assegurar_memoria_minima (struct vector *v)
{
	if (v->us == 0)
	{
		printf ("%s\n%s%zu\n%s\n",
		"Error al treure un element.",
		"Element restants: ", v->us,
		"Error generat al treure on no queda res."
		);

		exit (EXIT_FAILURE);
	}
}

/*2.3*		-afegir			Permet afegir un element	**/
/* Afegeix l'element entrat per dada */
// Comprova la capacitat i acte seguit afegeix la informació.
// En cas de no poder incrementar la memòria, atura el programa.
void vector_afegir (struct vector *v, void* dada)
{
	// Cas en que no hi hagi més capacitat.
	incrementar_capacitat_del_vector_en_necessitat (v);

	// Emmagatzemem la informació.
	memcpy (v->dada + v->us++*v->byts, dada, v->byts);
}

/*2.4*		-treure			Permet treure un element	**/
/* Treu l'últim element afegit */
// En cas de no haver cap element, aturarà el programa.
void* vector_treure (struct vector *v)
{
	// Comprovem que tingui mínim un element.
	assegurar_memoria_minima (v);

	// Retornem l'últim valor i actualitzem v->us.
	return v->dada + (--v->us)*(v->byts);
}

/*2.5*		-mostra			Mostra l'últim element		**/
/* Mostra l'últim element afegit */
// En cas de no haver cap element, aturarà el programa.
void* vector_mostra (struct vector *v)
{
	// Comprovem que tingui mínim un element.
	assegurar_memoria_minima (v);

	// Retornem l'últim valor.
	return v->dada + (v->us -1)*(v->byts);
}

	/*3*	Treballar com si fos una llista				**/
/* Totes les operacions que podriem demanar a una pila */
// Afegir element, mirar o treure un element.

/*3.0*		>cercar			Assegura que sigui vàlid	**/
/* Comprova que l'índex donat no està fora dels elements usats */
// En cas de no fer un bon ús, pararà el programa.
void error_cercar_un_element (struct vector *v, size_t i)
{
	if ( i >= v->us )
	{
		printf ("%s\n%s%zu, %s%zu\n%s\n",
		"Error al retornar un element.",
		"Elements usats: ", v->us,
		"Element demanat ", i,
		"Error generat al demanar un element fora de lloc"
		);

		exit (EXIT_FAILURE);
	}
}

/*3.1*		-indexat		Recuperem l'element indicat	**/
/* Donat un índex, retornarà l'element dins la llista */
// Capacitat d'aturar el programa.
void* vector_retorn_element (struct vector *v, size_t i)
{
	// Comprova el cas de que no existeixi l'element.
	error_cercar_un_element (v, i);

	// On està emmagatzemat.
	return v->dada + i*v->byts;
}

/*3.2*		-indexat invers		Recuperem l'element indicat	**/
/* Donat un índex, retornarà l'element dins la llista comptant del reves */
// Capacitat d'aturar el programa.
void* vector_retorn_element_reves (struct vector *v, size_t i)
{
	// Comprova el cas de que no existeixi l'element.
	error_cercar_un_element (v, i);

	// On està emmagatzemat.
	return v->dada + (v->us - i -1)*v->byts;
}

/*3.3*		-modifica		Edita l'element indicat		**/
/* Permet modificar un element amb la informació de dada */
// Capacitat d'aturar el programa.
void vector_modifica_element (struct vector *v, size_t i, void *dada)
{ memcpy (vector_retorn_element(v,i), dada, v->byts); }

/*3.4*		-modifica dimensió	Canvia el us sense afegir dades	**/
/* Permet modificar rapidament el tamany de la llista */
// Capacitat d'aturar el programa.
void vector_modifica_us (struct vector *v, size_t us)
{
	v->us = us;
	incrementar_capacitat_del_vector_en_necessitat (v);
}
