#include <stdio.h>
int main ()
{
	int I;
	scanf("%d",&I);
	if (I<0)
		printf("A IDADE DEVE SER MAIOR OU IGUAL A ZERO");
	else if (I<=10 || I>=18)
		printf("NAO");
	else
		printf("SIM");
}
