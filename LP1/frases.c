#include<stdio.h>
#include<stdlib.h>
int main (void)
{
	FILE *file;
	file = fopen("teste.txt","a");
	if (file == NULL)
	{
		printf("Arquivo nao pode ser aberto\n");
		getchar();
		exit(0);
	}
	char frase[100];
	while(fgets(frase,100,file)!=NULL)
	{
		printf();
	}
	fclose(file);
}
