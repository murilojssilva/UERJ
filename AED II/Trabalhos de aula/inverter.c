#include<stdio.h>
void inverter (char);
FILE *arq;
void main()
{
	char nome[100];
	char c;
	gets(nome);
	arq = fopen(nome,"r");
	inverter(c);
	fclose(arq);
}
void inverter (char c)
{
		if (c!=EOF)
		{
			inverter(getc(arq));
			printf("%c",c);
		}
}
