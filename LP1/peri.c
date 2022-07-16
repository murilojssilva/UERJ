#include <stdio.h>
#include <math.h>
main()
{
	int m;
	double j,e;
	scanf("%lf",&e);
	scanf("%lf",&j);
	scanf("%d",&m);
	if (e<0)
		printf("O VALOR DO EMPRESTIMO NAO PODE SER NEGATIVO");
	else if (j<0)
		printf("A TAXA DE JUROS NAO PODE SER NEGATIVA");
	else if (m<0)
    	printf("A QUANTIDADE DE MESES NAO PODE SER NEGATIVA");
	else
		printf("%.2lf",e*pow(1+(0.01*j),m));
}
