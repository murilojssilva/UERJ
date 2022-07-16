/*
Murilo de Jesus Santos Silva
EXC01 - Fibonacci
*/
#include <stdio.h>
int n,numCR;
double fibonacci (int n)//Só consegui fazer com que aparecesse os valores corretos usando double
{	
	numCR++;
	if (n < 2)
		return n;
	else	
		return fibonacci(n-1) + fibonacci(n-2);
}
main()
{
	for (n=10;n<=100;n+=10)
	{
		numCR=0;//feito para não acumular os valores dos fibonaccis calculdados anteriormente
		fibonacci(n);//executando a função
		printf("\nN = %d\nFibonacci = %.0lf\nChamadas recursivas = %.0d\n\n",n,fibonacci(n),numCR);
	}
}
/*
Os valores do Fibonacci e das chamadas recursivas são:

Saídas:

N = 10
Fibonacci = 55
Chamadas recursivas = 176


N = 20
Fibonacci = 6765
Chamadas recursivas = 21890


N = 30
Fibonacci = 832040
Chamadas recursivas = 2692536


N = 40
Fibonacci = 102334155
Chamadas recursivas = 331160280

OBS: A partir do N=50, o valor do Fibonacci demora muito para ser calculado, por isso que não foram apresentados os valores do Fibonacci e o de chamadas recursivas para N=50, N=60, N=70, N=80, N=90 e N=100.
*/
