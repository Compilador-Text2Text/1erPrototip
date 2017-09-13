#include <stdio.h>

FILE *inicialitzar_lectura_fitxer (char *nom);
void finalitzar_lectura_fitxer (FILE *punter_fitxer);
char seguent_caracter (FILE *punter_fitxer);
int seguenta_linia (FILE *punter_fitxer, int llargada, char *linia);
