#include<stdio.h>
#include<stdlib.h>
int main (void)
{
	FILE *file;
	file = fopen("teste.txt","r");
	if (file == NULL)
	{
		printf("Arquivo nao pode ser aberto\n");
		exit(0);
	}
	else
	{
		char a[1000];
		fgets(file,"%s",a);
		printf("%s",a);
		fclose(file);
		return 0;
	}
}
