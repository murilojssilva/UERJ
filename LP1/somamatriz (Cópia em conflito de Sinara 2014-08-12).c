#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i,j=0;
char removerAspas[](char nome[],int i)
{
	if (i<0)
		return nome;
	else
	{
		removerAspas(nome,i-1);
		if (nome[i]!='"')
			nome[j++]=nome[i];
		return nome;
	}
}
int main()
{
	FILE *file;
	int i,j,m,n;
	int **A,**B,**C;
	char nome[100],nomes[98];
	fscanf(stdin,"%s",nome);
	i=strlen(nome);
	removerAspas(nome,i);
	i=0;
	j=0;
	file=fopen(nome,"r");
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
		for (i=0;i<m;i++)
			A[i]=(int *) calloc (n,sizeof(int));
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
				fscanf(file,"%i",&A[i][j]);
		B=(int **) calloc (m,sizeof(int));
		for (i=0;i<m;i++)
			B[i]=(int *) calloc (n,sizeof(int));
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
				fscanf(file,"%i",&B[i][j]);
		C=(int **) calloc (m,sizeof(int));
		for (i=0;i<m;i++)
			C[i]=(int *) calloc (n,sizeof(int));
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
				C[i][j]=A[i][j]+B[i][j];
		for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
			{
				fprintf(stdout,"%i",C[i][j]);
				if (j!=n-1)
					putchar(' ');
			}
			if (i!=m-1)
				putchar('\n');
		}
	fclose(file);
	}
}
