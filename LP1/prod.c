#include<stdio.h>
int prod(int i,int a, int b);
int main(void)
{
	int a,b,i;
	printf("Digite 2 numeros inteiros\n");
	scanf("%d",&a);
	scanf("%d",&b);
	prod(i,a,b);
	printf("%d\n",prod(i,a,b));
}
int prod(int i,int a, int b)
{
	int produto=1;	
	if (a>b)
		return 0;
	else	
	for (i=a;i<=b;i++)
		produto*=i;
	return produto;
}
