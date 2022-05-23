/*Faça um programa que lê um número N e sorteia N números inteiros (entre 0 e 100), gravando todos em um arquivo texto. A primeira linha do arquivo deverá conter a quantidade de números.*/
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
