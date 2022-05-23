#include<stdio.h>
int n,i,V[10],CR=0;
int fibonacci(int n)
{
	CR++;
	if (n<2)
	{
		//V[n]++;
		return n;
	}
	else
		return fibonacci(n-1) + fibonacci(n-2);
}
int main()
{
	scanf("%d",n);
	fibonacci(n);
	printf("Fibonacci: %d\nChamadas Recursivas: %d\n",fibonacci(n),CR);
	for (i=0;i<n;i++)
	{
		printf("Vetor de Chamadas Recursivas: %d",V[i]);
	}
}
//int fibonacci(int n);


