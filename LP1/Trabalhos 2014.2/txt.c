#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
	char c,nome[100];
	scanf("%s",nome);
	FILE *file = fopen(nome,"r");
	while ((c=fgetc(file))!=EOF)
	{
		putchar(c);
	}
}
