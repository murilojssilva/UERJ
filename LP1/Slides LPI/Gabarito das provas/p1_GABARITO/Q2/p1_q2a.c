
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
	printf("soma_m5(%d, %d)\n", a, b);
	if (a>b)
		return 0;
	if (a%5)
		return soma_m5(a+1,b);
	return (a + soma_m5(a+1,b));
}
