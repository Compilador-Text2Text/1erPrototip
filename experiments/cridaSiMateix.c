#include <stdio.h>

typedef int (*my_pointer)(my_pointer);


int end (my_pointer *l)
{
	printf ("adeu");
return 0;
}
int lol (my_pointer *l)
{
	printf ("hola");
	*l = end;
return 1;
}
int
main ()
{
	my_pointer m = lol;

	while (m ( &m )) printf ("\n");
return 0;
}
