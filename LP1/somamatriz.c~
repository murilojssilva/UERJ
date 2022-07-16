#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *file;
	int i,j,m,n;
	int **A,**B,**C;
	char nome[100],nomes[98];
	fscanf(stdin,"%s",nome);
	if (nome[0]=='"')
	{
		if (nome[strlen(nome)-1]='"')
		{
			for (i=1;i<strlen(nome)-1;i++)
			{
				nomes[i-1]=nome[i];
			}
			file=fopen(nomes,"r");
		}
	}
	else
	{
		file=fopen(nome,"r");
	}
	if (file==NULL)
	{
		perror("Erro ao abrir o arquivo");
		return 0;
	}
	else
	{	
		fscanf(file,"%d;%d",&m,&n);
		fprintf(stdout,"%d;%d\n",m,n);
		A=(int **) calloc (m,sizeof(int));
		B=(int **) calloc (m,sizeof(int));
		C=(int **) calloc (m,sizeof(int));
		for (i=0;i<m;i++)
		{
			A[i]=(int *) calloc (n,sizeof(int));
			B[i]=(int *) calloc (n,sizeof(int));
			C[i]=(int *) calloc (n,sizeof(int));
		}
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
				fscanf(file,"%i",&A[i][j]);	
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
			{
				fscanf(file,"%i",&B[i][j]);
				C[i][j]=A[i][j]+B[i][j];
			}
		for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
			{
				fprintf(stdout,"%i",C[i][j]);
				if (j!=n-1)
					putchar(' ');
			}
			putchar('\n');
		}
	fclose(file);
	}
}
