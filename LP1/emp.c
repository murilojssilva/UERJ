#include <stdio.h>
#include <math.h>

int main() {
	double emprestimo, divida;
	printf("Digite o valor do emprestimo:");
	scanf("%lf",&emprestimo);
	divida=emprestimo*(pow(1.05),6);
	printf("O valor da divida e:%.2lf\n", divida);
	return 0;	
}
