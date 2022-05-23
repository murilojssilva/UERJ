#include <stdio.h>
int main ()
{
	int n;
	scanf("%d",&n);
	if (n<0)
		printf("O NUMERO DEVE SER MAIOR OU IGUAL A ZERO");
	if (n%3==0&&n%2==0)
		printf("SIM");
	else
		printf("NAO");
}

