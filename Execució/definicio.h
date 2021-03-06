#ifndef DEFINICIO_PER_EXECUCIO_H_
#define DEFINICIO_PER_EXECUCIO_H_

#include <stdlib.h>

/**
!!!
 *
 * Índex
 *
 * 1	Poder generar codi
 * 1.1		valor			{ void*, char, int }
 *
 * 1.2		enum tipus		{ void,  char, int }
 * 1.3		descriptor valor	Anàlisi semàntica, ex: (int **)
 *
 * 1.4		enum localització	{ codi, variable, funció }
 * 1.5		localització		Saber on està la informació
 *
 * 1.6		paraula			Per generar frases
 * 1.7		frase			Vector de paraules
 * 1.8		codi			Vector de frases
 *	1.7 i 1.8 són només conceptuals?
 *
 * 2	Definir la funció
 * 2.1		variables		Informació d'una variable
 * 2.2		Descriptor		Informació d'una funció
 * 2.3		Memòria d'execució	On guardem que passa
 * 2.4		Funció Dinàmica		Múltiples crides a funcions
 *
 **/

	/*1*	Poder generar codi	**/
/* Totes les dades necessàries per a poder generar el codi */
// En cas de voler afegir un nou tipus, important modificar el 1.1 i el 1.2
// També tenir present generar les funcions adequades pels nous tipus.

/*1.1*		valor	{ void*, char, int }				**/
/* Per simplificació, emmagatzemem els qualsevol valor en un sol punt */
// Necessari per l'execució del programa.
union
valor
{
	void *punter;
	char  caracter;
	int   enter;
};

/*1.2*		enum tipus	{ void, char, int }			**/
/* Poder saber quin valor tenim emmagatzemat */
// Per saber on extreure la informació en el cas que sigui per el codi.
enum
tipus_valor
{
	Cap,	// Fet anar pel descriptor de funcions.
	Void,
	Char,
	Int
};

/*1.3*		localització	Anàlisi semàntic, tipus: ex (int **)	**/
/* Descriu com ha de ser el valor */
// Ajuda a l'anàlisi semàntica, per ajustar les funcions.
// Dependència: 1.2
struct
descriptor_valor
{
	enum tipus_valor tipus;
	size_t vegades_punter;
};

/*1.4*		enum localització	{ codi, variable, funció }	**/
/* En el codi, ens permet saber d'on extreure la informació */
// Serveix per a fer un switch i fer l'operació adient
enum
localitzacions
{
	Codi,		// Les dades estan a auxiliar del codi.

	Arguments,	// Variables d'arguments.
	Local,		// Variables locals.
	Global,		// Variables globals.

	Funcio,		// Creació d'una funció pròpia.
	Retorn,		// Retorn d'una funció pròpia.
	NoRetorn,	// Quan no hi ha cap retorn.

	Sistema		// Funcions de sistema.
};

/*1.5*		localització		Saber on està la informació	**/
/* Amb aquesta informació podem saber amb exactitud on trobar les dades */
// Dependència: 1.4
struct
localitzacio
{
	enum localitzacions quin_vector_es;
	size_t lloc_relatiu;
};

/*1.6*		paraula			Per generar frases		**/
/* Format per emmagatzemar les instruccions */
// descriptor_valor:
// Serveix per a poder fer l'anàlisi semàntica.
//
// localització_completa:
// Tant si són dades al codi, demanar una variable o cridar a una funció,
// serveix per trobar la informació al indret correcte.
//
// auxiliar:
// Dues funcionalitats:
//	- Si prové del codi
//	- Per saber quants arguments necessita la funció
//
// Dependència: 1.1, 1.3 i 1.5
struct
paraula_codi
{
	struct descriptor_valor	descriptor;
	struct localitzacio	localitzacio_completa;
	union  valor		auxiliar;
};

/*1.7*		frase			Vector de paraules		**/
/* Format per emmagatzemar una frase */
// !!! No m'acaba de convèncer, m'agradaria més crear el vector per defecte
// https://stackoverflow.com/questions/3536153/c-dynamically-growing-array
struct
frase
{
	struct paraula_codi *paraula;
	size_t mida;
};

/*1.8*		codi			Vector de frases		**/
/* Format que emmagatzema tot el codi */
// !!! No m'acaba de convèncer, m'agradaria més crear el vector per defecte
// https://stackoverflow.com/questions/3536153/c-dynamically-growing-array
struct
codi
{
	struct frase *frase;
	size_t mida;
};

	/*2*	Definir la funció	**/
/* Tota funció ha d'estar definida per a poder ser cridada */
// Pot canviar el comportament de les variables.
// Dependència: 1.1 1.3 1.8

/*2.1*		variables		Informació d'una variable	**/
/* Dades interessants per tenir una variable */
// Normalment sobra informació, el faig anar per simplificació.
// Els important normalment és el valor i el descriptor.
// Dependència: 1.1 1.3
// !!! Més coses de
struct
variable
{
	// Essencial.
	union valor	valor;

	// Depurar.
	char* nom;

	// Anàlisi semàntica i pel descriptor de funció.
	struct descriptor_valor descriptor;

	// Anàlisi semàntica.
	int usat;
	int inicialitzat;
	// !!! Podríem posar també la dimensió
	// (valor mínim, mida) pels vectors.
};


struct
variables
{
	size_t mida;
	struct variable* variables;
};


/*2.2*		Descriptor		Informació d'una funció		**/
/* Dades per a definir correctament una funció */
// 4 elements importants: arguments, variables, semàntica i execució
// Dependència: 1.2 1.8 2.1
struct
descriptor_funcio
{
	// Arguments.
	struct variables arguments;	// Útil per la semàntica.
	enum tipus_valor adicionals;	// Nombre arbitrari d'arguments.

	// Variables locals.
	struct variables locals;

	// Anàlisi Semàntica.
	size_t longitud_maxima_frases;
	// Definit uns arguments, el retorn sempre serà el mateix.
	// !!!
	enum {esEstable, no_esEstable} funcio_estable;

	// Execució.
	size_t dimencio_memoria_dExecucio;
	struct codi codi;
};

/*2.3*		Memòria d'execució	On guardem que passa		**/
/* Per a poder enviar arguments i recuperar el que retorna la funció */
// Guardar les sortides de les funcions.
// També per enviar els arguments a les funcions.
// Dependències: 1.1 1.3
struct
element_dExecucio
{
	// Anàlisi semàntica.
	struct descriptor_valor descriptor;

	// La informació.
	union valor valor;

	// Per saber el valor de la variable.
	void* punter;
	struct localitzacio localitzat;
};

struct memoria_dExecucio
{
	size_t capacitat;
	size_t us;
	struct element_dExecucio *memoria;
};

/*2.4*		Funció Dinàmica		Múltiples crides a funcions	**/
/* Per a generar múltiples crides a les funcions */
// Guarda les variables de cada crida.
// També sap en tot moment per on va de la funció.
// Dependències: 2.2 2.3
struct
funcio_dinamica
{
	// Arguments.
	struct element_dExecucio *memoria_dExecucio_dArguments;
	struct variables arguments;	// Anàlisis semàntica.

	// Variables locals.
	struct variables locals;

	// Execució.
	struct memoria_dExecucio memoria_dExecucio;
	size_t fila, columna;
	struct descriptor_funcio *descriptor;
};

#endif // DEFINICIO_PER_EXECUCIO_H_
