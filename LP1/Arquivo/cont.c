#include <stdio.h>
#include <string.h>
//#include <conio.h>
int main()
{
	FILE *file;
	char nome[100000],frase[100000],c;
	char *result;
	int tot=0,imp=0,lin=0;
	fscanf(stdin,"%s",nome);
	file=fopen(nome,"w");
	while (!feof(file))
	{	
		result = fgets(frase,100000,file);
		if (frase=="FIM\n")
			fclose(file);
	}
	fclose(file);
	file=fopen(nome,"r");
	while ((c=getc(file))!=EOF)
	{
		tot++;
		if (c=='\n')
			lin++;
		else
			if (c!='\n'||c!=' '||c!='\t')
				imp++;
	}
	printf("Total: %d\nImprimiveis: %d\nLinhas: %d\n",tot,imp,lin);
	fclose(file);
}
