#include <stdio.h>
#include <math.h>
main(int argc, char *argv[])
{
	double valor = 1.570796327;
	for(valor=0; valor < 3.1416; valor+=0.1)
		printf("sen(%3.2f) = %3.2f\n", valor, sin(valor));
}
