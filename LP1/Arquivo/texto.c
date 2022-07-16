#include <stdio.h>
main()
{
	FILE *file;
	file=fopen("Texto.txt","w");
	char texto[100000000];
	int i=1;
	do
	{
		gets(texto);
		fprintf(file,"%s",texto);
		char texto[100000000];
		i++;
	}while (texto!="FIM"||i<50);
	fclose(file);
}
