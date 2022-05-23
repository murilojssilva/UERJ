#include<stdio.h>
int menor(int n)
{
	int i, vet[n];
	menor=1000000;
	for (i=0;i<n;i++)
	{
		if (vet[i]<menor)
			menor=vet[i];
	}
	return menor;
}
int media (int n)
{
	int i,soma,media;
	for (i=0;i<n;i++)
	{
		soma+=vet[i];
	}
	media=soma/n;
	return media;
}
int main()
{
	FILE *file;
	FILE *file2;
	file = fopen("sorteio.txt","r");
	file2 = fopen("menor.txt","w");
	menor(vet[]);
	media(vet[]);
	fprintf(file,"Menor: %d\nMedia: %d",menor,media);
	fclose(file2);
	fclose(file);
}
