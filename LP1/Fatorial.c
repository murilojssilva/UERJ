/*
Murilo de Jesus Santos Silva
EXC01 - Fatorial
*/
#include <stdio.h>
int n,numCR=0;
double fatorial (int n)
/*recursão para calcular o fatorial. OBS: Eu só conseguir os valores dos
 fatoriais utilizando a função fatorial como uma variável double*/
{
	numCR++;//contagem das chamadas recursivas
	if (n < 2)//caso infantil
		return 1;
	else
		return n * fatorial(n-1);
}
main()
{
	
	for (n=10;n<=100;n+=10)
	{
		fatorial(n);//executando a funÃ§Ã£o fatorial
		printf("\nN = %d\nFatorial = %0.lf\nNumero de chamadas = %d\n\n",n,fatorial(n),numCR);
		numCR=0;
	}
}
/*
Saídas:
	
N = 10
Fatorial = 3628800
Numero de chamadas = 10


N = 20
Fatorial = 2432902008176640000
Numero de chamadas = 20


N = 30
Fatorial = 265252859812191030000000000000000
Numero de chamadas = 30


N = 40
Fatorial = 815915283247897680000000000000000000000000000000
Numero de chamadas = 40


N = 50
Fatorial = 30414093201713376000000000000000000000000000000000000000000000000
Numero de chamadas = 50


N = 60
Fatorial = 832098711274139160000000000000000000000000000000000000000000000000000
0000000000000
Numero de chamadas = 60


N = 70
Fatorial = 119785716699698900000000000000000000000000000000000000000000000000000
00000000000000000000000000000000
Numero de chamadas = 70


N = 80
Fatorial = 715694570462637790000000000000000000000000000000000000000000000000000
00000000000000000000000000000000000000000000000000
Numero de chamadas = 80


N = 90
Fatorial = 148571596448176070000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000000000
Numero de chamadas = 90


N = 100
Fatorial = 933262154439441020000000000000000000000000000000000000000000000000000
00000000000000000000000000000000000000000000000000000000000000000000000000000000
000000000
Numero de chamadas = 100
*/
