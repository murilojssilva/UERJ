#include <stdio.h>
#include <stdlib.h>
main()
{
	char *x;
	x = malloc(5);
	gets(x);
	toupper((x));
	puts(x);
}
