#include <stdio.h>

int soma_m5(int, int);

int main(void)
{
	int a, b;
	printf("Digite 2 numeros inteiros:\n");
	scanf("%d", &a);
	scanf("%d", &b);
	printf("Resultado: %d\n", soma_m5(a,b));
	return 0;
}

int soma_m5(int a, int b)
{
	int i, soma=0;
	for (i=a; i<=b; i++)
		if ((i%5)==0)
			soma+=i;
	return soma;
}
