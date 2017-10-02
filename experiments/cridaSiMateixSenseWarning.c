#include <stdio.h>
struct tela
{
	int (*func) (struct tela*);
};

int end (struct tela *l)
{
	printf ("adeu");
return 0;
}
int lol (struct tela *l)
{
	printf ("hola");
	l->func = end;
return 1;
}

int
main ()
{
	struct tela l = {.func = lol};

	while (l.func(&l)) printf ("\n");
	printf("\n");
return 0;
}
