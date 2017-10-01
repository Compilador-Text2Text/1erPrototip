#include <stdio.h>

// Tenir en compte const (constant) i volatile (per a crear threads sense problemes)

void foo()
{
	int a = 10;
	static int sa = 10;

	a += 5;
	sa += 5;

	printf("a = %d, sa = %d\n", a, sa);
}


int main()
{
	int i;

	for (i = 0; i < 10; ++i)
	foo();
}
