/**
 *
 * Índex
 *
 * 1	Emmagatzemar informació
 * 1.1		valor			{ void*, char, int }
 * 1.2		enum tipus		{ void,  char, int }
 * 1.3		descriptor		Semàntic, tipus: ex (int **)
 * 1.4		enum localització	{ codi, variable, funció }
 * 1.5		localització		Saber on està la informació
 *
 **/

	/*1*	Emmagatzemar informació	**/
/* Informació que necessitem per emmagatzemar les dades */
// En cas de voler afegir un nou tipus, important modificar el 1.1 i el 1.2
// També tenir present generar les funcions adequades pels nous tipus.

/*1.1*		valor	{ void*, char, int }				**/
/* Per simplificació, emmagatzemem els qualsevol valor en un sol punt */
// Necessari per l'execució del programa.
union
{
	void *punter;
	char  caracter;
	int   enter;
} valor;

/*1.2*		enum tipus	{ void, char, int }			**/
/* Poder saber quin valor tenim emmagatzemat */
// Per saber on extreure la informació.
enum
tipus_valor
{
	Void,
	Char,
	Int
};

/*1.3*		localització	Semàntic, tipus: ex (int **)		**/
/* Descriu com ha de ser el valor */
// Ajuda a l'anàlisi semàntica, per ajustar les funcions.
// Dependència: 1.2
struct
{
	enum tipus_valor tipus;
	unsigned int vegades_punter;
} descriptor;

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

	Funcio,		// Funcions pròpies.
	Sistema		// Funcions de sistema.
};

/*1.5*		localització		Saber on està la informació	**/
/* Amb aquesta informació podem saber amb exactitud on trobar les dades */
// Dependència: 1.4
struct
{
	enum localitzacions quin_vector_es;
	unsigned int lloc_relatiu;
} localitzacio;
