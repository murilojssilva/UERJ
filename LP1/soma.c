#include<stdio.h>
int soma(int valor,int a,int b);
int main()
{
	int a,b,valor;
	soma(valor,a,b);
	printf("%d",valor);
}
int soma(int valor,int a,int b)
{
	scanf("%d %d",&a,&b);
	valor=a+b;
	printf ("%d\n",valor);
	return valor;
}

