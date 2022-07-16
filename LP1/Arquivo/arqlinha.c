/*
Faça um programa que conte o número de caracteres
imprimíveis, o número de linhas e o número total de
caracteres de um arquivo. O nome do arquivo deve ser
fornecido pelo teclado.
*/
#include <stdio.h>
#include <string.h>
void main(int argc, char *argv[])
{
	FILE *fp;
	char prog [10000];
	fscanf(stdin,"Nome do arquivo texto: %s",prog);
	fp=fopen(prog,"r");
	char c;
	int carac=0,linha=0 ,imp=0;
	while ((c = getc(prog)) != EOF)
	{
		carac++;
		if (c!=' '||c!='\t'||c!='\n')
			imp++;
		else
			if (c=='\n')
				linha++;
	}
	fclose(prog);
	fclose(fp);
	printf("Qtd de caracteres: %d\nQtd de linhas: %d\nQtd de caracteres imprimives: %d\n",carac, linha,imp);
}

