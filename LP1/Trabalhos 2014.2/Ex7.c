#include<stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *file1,*file2;
int **A,**B,**C;
char nomearq1[100],nomearq2[100],aux1,aux2;
int i,j,k,l1,l2,c1,c2,tam1,tam2,n1,n2,a1,a2;
main()
{
	fscanf(stdin,"%s",nomearq1);
	fscanf(stdin,"%s",nomearq2);
	file1 = fopen(nomearq1,"r");
	file2 = fopen(nomearq2,"r");
	fscanf(file1,"%c %d %d %d %d",&aux1,&a1,&c1,&l1,&tam1);
	fscanf(file2,"%c %d %d %d %d",&aux2,&a2,&c2,&l2,&tam2);
	if (l2==c1)
	{
		fprintf(stdout,"%i %i %i %i ",a1,c2,l1,tam2);
		A = (int **) malloc(l1*tam1);
		B = (int **) malloc(l2*tam2);
		C = (int **) malloc(l1*tam1);
		for (i=0;i<l1;i++)
		{
			A[i] = (int *) malloc(c1*tam1);
		}
		for (i=0;i<l1;i++)
			for (j=0;j<c1;j++)
		{
				fscanf(file1,"%d",&A[i][j]);
				//fprintf(stdout,"%d ",A[i][j]);
		}
		for (i=0;i<l2;i++)
		{
			B[i] = (int *) malloc(c2*tam2);
		}
		for (i=0;i<l2;i++)
			for (j=0;j<c2;j++)
			{
				fscanf(file2,"%d",&B[i][j]);
				//fprintf(stdout,"%d ",B[i][j]);
			}
		for (i=0;i<l1;i++)
		{
			C[i] = (int *) malloc(c2*tam2);
		}
		for (i=0;i<l1;i++)
			for (j=0;j<c2;j++)
			{
				int soma=0;
				for (k=0;k<c1;k++)
				{
					soma+=A[i][k]*B[k][j];
				}
				C[i][j] = soma;	
			}
		for (i=0;i<l2;i++)
			for (j=0;j<c2;j++)
			{
				fprintf(stdout,"%i ",C[i][j]);
			}
		free(A);
		free(B);
		free(C);
	}
	else
	{
		printf("Erro dimensoes incompativeis\n");
	}
}
