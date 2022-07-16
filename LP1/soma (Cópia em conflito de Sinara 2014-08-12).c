#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i,j=0;
char nome[100];
int *A,*B,*C;
void removerAspas(char nome[],int i)
{
	if (i<0)
		nome[i];
	else
	{
		removerAspas(nome,i-1);
		if (nome[i]!='"')
			nome[j++]=nome[i];
	}
}
int main()
{
	FILE *file;
	int m,n;
	fscanf(stdin,"%s",nome);
	i=strlen(nome);
	removerAspas(nome,i);
	nome[j]='\0';
	puts(nome);
	j=0;i=0;
	file=fopen(nome,"r");
	if (!file)
	{
		perror("Erro ao abrir o arquivo");
		return 0;
	}
	else
	{	
		fscanf(file,"%d;%d",&m,&n);
		fprintf(stdout,"%d;%d\n",m,n);
		A=(int *) calloc (m,sizeof(int));
		B=(int *) calloc (m,sizeof(int));
		C=(int *) calloc (m,sizeof(int));
		for (i=0;i<m;i++)
		{
			A[i]=(int *) calloc (n,sizeof(int));
			B[i]=(int *) calloc (n,sizeof(int));
			C[i]=(int *) calloc (n,sizeof(int));
		}
		free(A);
		free(B);
		free(C);
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
