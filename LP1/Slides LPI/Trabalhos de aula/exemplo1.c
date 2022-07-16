#include <stdio.h>
main()
{
	printf("O tamanho de um (char) é de %ld byte(s)\n", sizeof(char));
	printf("O tamanho de um (short) é de %ld byte(s)\n", sizeof(short));
	printf("O tamanho de um (int) é de %ld byte(s)\n", sizeof(int));
	printf("O tamanho de um (long) é de %ld byte(s)\n", sizeof(long));
	printf("O tamanho de um (long long) é de %ld byte(s)\n\n", sizeof(long long));
	printf("O tamanho de um (float) é de %ld byte(s)\n", sizeof(float));
	printf("O tamanho de um (double) é de %ld byte(s)\n", sizeof(double));
	printf("O tamanho de um (long double) é de %ld byte(s)\n", sizeof(long double));
}
