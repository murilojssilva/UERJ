#include<stdio.h>
int V[10],i=0,soma=0,n=9;
int somaVetor(int V[],int n)
{
	if (n<1)
		return (V[n]);
	else
		return somaVetor(V,n-1)+V[n];
}
int main()
{
	for (i=0;i<10;i++)
		V[i]=i+1;
	printf("%d\n",somaVetor(V,n));
	
}
