#include <stdio.h>
double n=0,fib;
int _contfib;
double fibonacci (double n)
{
	_contfib++;
	if (n < 2)
		fib = n;
	else
		fib = fibonacci(n-1) + fibonacci(n-2);
}
main()
{
	
	while (n<101)
	{
		_contfib=0;
		fib=0;		
		fibonacci(n);
		printf("\nN = %.0lf\nFibonacci = %.0lf\nNumero de chamadas = %d\n\n",n,fib,_contfib);
		n+=10;		
	}
}

