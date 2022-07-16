#include <stdio.h>
int n;
int fatorial(int n);
int main()
{
	scanf("%i",&n);
	printf("%i\n",fatorial(n));
}
int fatorial(int n)
{
	if (n<2)
		return n;
	else
		return n * fatorial(n-1);
}

