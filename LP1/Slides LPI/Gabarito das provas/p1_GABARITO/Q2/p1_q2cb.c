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
	if (a%5)
		a = a + 5 - (a%5);
	for (i=a; i<=b; i+=5)
	{
		printf("%d\n", i);
		soma+=i;
	}
	return soma;
}
