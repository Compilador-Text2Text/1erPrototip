#include "llegir-fitxer.h"
/**
  * Codi per a veure com és comporta el fgets i fgetc
  */

int
main (int argc, char *argv[])
{
	// Necessitem obrir el codi `assemblador'
	FILE *punter_fitxer_assemblador;

	punter_fitxer_assemblador = inicialitzar_lectura_fitxer (argv[1]);
	finalitzar_lectura_fitxer (punter_fitxer_assemblador);
// EOF vs feof
// Pendent veure que passa quan poses un valor menor a la línia
	return 0;
}
