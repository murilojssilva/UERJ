#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{

	FILE * arquivo;

	int **A,**B,**C;
	int a,b,i,j;
	char arqprincipal[100];
	char arqaux[100];
	
	fscanf(stdin,"%s",arqprincipal);
	
	if ((arqprincipal[0]=='"') && (arqprincipal[strlen(arqprincipal)-1]=='"'))
	{
		for(i=1;i<strlen(arqprincipal);i++)
		{	
			arqaux[i-1]=arqprincipal[i];
		}

		arquivo=fopen(arqaux,"r");	
		fscanf(arquivo,"%d;%d",&a,&b);
		fprintf(stdout,"%d;%d\n",a,b);

		A=((int **) malloc(a * sizeof(int *)));
		for (i=0;i<a;i++)
		{
			A[i]=((int *) malloc(a * sizeof(int *)));
		}
		for (i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				fscanf(arquivo,"%d",&A[i][j]);	
			}
		}

		B=((int **) malloc(b * sizeof(int *)));
		for (i=0;i<a;i++)
		{
			B[i]=((int *) malloc(a * sizeof(int *)));
		}
		for (i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				fscanf(arquivo,"%d",&B[i][j]);	
			}
		}

		C=((int **) malloc(a * sizeof(int *)));
		for (i=0;i<a;i++)
		{
			C[i]=((int *) malloc(a * sizeof(int *)));
		}	
		for (i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				C[i][j]=A[i][j]+B[i][j];
			}
		}
		for (i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				fprintf(stdout,"%d",C[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		arquivo=fopen(arqprincipal,"r");
		fscanf(arquivo,"%d;%d",&a,&b);
		fprintf(stdout,"%d;%d\n",a,b);

		A=((int **) malloc(a * sizeof(int *)));
		for (i=0;i<a;i++)
		{
			A[i]=((int *) malloc(a * sizeof(int *)));
		}		
		for (i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				fscanf(arquivo,"%d",&A[i][j]);	
			}
		}

		B=((int **) malloc(a * sizeof(int *)));
		for (i=0;i<a;i++)
		{
			B[i]=((int *) malloc(a * sizeof(int *)));
		}	
		for (i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				fscanf(arquivo,"%d",&B[i][j]);	
			}
		}

		C=((int **) malloc(a * sizeof(int *)));
		for (i=0;i<a;i++)
		{
			C[i]=((int *) malloc(a * sizeof(int *)));
		}	
		for (i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				C[i][j]=A[i][j]+B[i][j];
			}
		}
		for (i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				fprintf(stdout,"%d ",C[i][j]);
			}
			printf("\n");
		}	
	}
	fclose(arquivo);
	free(A);
	free(B);
	free(C);
}	
