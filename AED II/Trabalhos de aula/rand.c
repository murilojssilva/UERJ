/*Fa�a um programa que l� um n�mero N e sorteia N n�meros inteiros (entre 0 e 100), gravando todos em um arquivo texto. A primeira linha do arquivo dever� conter a quantidade de n�meros.*/
#include<stdio.h>
int main()
{
	FILE *file;
	file = fopen("sorteio.txt","w");
	int n,i;
	scanf("%i",&n);
	int vet[n];
	for (i=0;i<n;i++)
	{
		vet[i]=rand(0,100);
		fprintf(file,"%i ",vet[i]);
	}
	fclose(file);
	return 0;
}
