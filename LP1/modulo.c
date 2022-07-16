#include<stdio.h>
void ler(int a,int b)
{
	scanf("%d",&a);
	scanf("%d",&b);
	if (a<0)
		a=a*(-1);
	if (b<0)
		b=b*(-1);
}
int soma(int valor,int a,int b)
{
	valor=0;	
	valor=a+b;
	return valor;
}
int main()
{
	int a,b;
	ler(a,b);
	printf("%d",soma(valor,a,b));
}
