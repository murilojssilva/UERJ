#include <stdio.h>
void imprime(char);
FILE * arquivo;
int main()
{
	char nomeArq[100];
	char c;
	scanf("%s",nomeArq);
	arquivo = fopen(nomeArq,"r");
	if(arquivo == NULL)
	{
		fprintf(stderr,"Erro ao abrir o arquivo %s",nomeArq);
		exit(1);
	}
	imprime(getc(arquivo));
	return 0;
}
void imprime(char c)
{
	if(c != EOF)
	{
		imprime(getc(arquivo));
		printf("%c",c);
	}
}
