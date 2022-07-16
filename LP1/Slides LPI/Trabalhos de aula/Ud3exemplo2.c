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
	printf("O tamanho de um (long double) é de %ld byte(s)\n\n", sizeof(long double));

	printf("O tamanho de um (char[2]) é de %ld byte(s)\n", sizeof(char[2]));
	printf("O tamanho de um (char[2][2]) é de %ld byte(s)\n", sizeof(char[2][2]));
	printf("O tamanho de um (char [2][2][2]) é de %ld byte(s)\n\n", sizeof(char[2][2][2]));

	printf("O tamanho de um (int *) é de %ld byte(s)\n", sizeof(int*));
	printf("O tamanho de um (char *) é de %ld byte(s)\n\n", sizeof(char*));

	printf("O tamanho de um (union u_tag{int ival; float fval; char *sval; }) é de %ld byte(s)\n", sizeof(union {int ival; float fval; char *sval; }));
	printf("O tamanho de um (struct{int ival; float fval; char *sval; }) é de %ld byte(s)\n", sizeof(struct {int ival; float fval; char *sval; }));
	printf("O tamanho de um (enum {jan=1, fev, mar, abril, mai}) é de %ld byte(s)\n", sizeof(enum {jan=1, fev, mar, abril, mai}));
	printf("O tamanho de um (enum {amarelo=10, vermelho, azul}) é de %ld byte(s)\n", sizeof(enum {amarelo=10, vermelho, azul}));
  printf("O tamanho de um struct Point3d é de %ld bytes(s) \n", sizeof(struct{float x,y,z;}));
}
