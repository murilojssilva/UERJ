#include<stdio.h>
int main()
{
	FILE *file;
	char nome[100];
	int nl=0,ni=0,nt=0;
	fscanf(stdin,"%s",nome);
	file=fopen(nome,"r");
	if (file==NULL)
	{
		fprintf(file,"O arquivo %s não foi encontrado",nome);
		return 0;
	}
	else
	{
		char c;
		if ((c=getc(file))!=EOF)
			nl++;
		do
		{
			nt++;
			if (c != '\n' ||c != ' ' || c!= '\t' )
				ni++;
			if (c=='\n')
				nl++;
		}while((c=getc(file))!=EOF);
	}
	printf("%i\n%i\n%i\n",nt,nl,ni);
	fclose(file);
}
