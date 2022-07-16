#include <stdlib.h>
#include <stdio.h>

int wrap(char caminho[], int n)
{
	char c;
	int i=0,qtd=0;
	FILE * input;
	FILE * output;
	input = fopen(caminho, "rt");
	output = fopen("saida.txt", "wt");

	while ((c=fgetc(input))!=EOF)
	{
		fputc(c, output);
		i++;
		if (i==n)
		{
			fputc('\n', output);
			qtd++;
			i=0;
		}
	}
	fclose(input);
	fclose(output);
	return qtd;
}
