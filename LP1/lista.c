#include<stdio.h>
struct lista
{
	int valor;
	struct lista *prox;
};
struct lista m1, m2, m3;
struct lista *cab = &m1;
int main(void)
{
	m1.valor=10;
	m2.valor=20;
	m3.valor=30;
	m1.prox=&m2;
	m2.prox=&m3;
	m3.prox=(struct lista *)0;
	while (cab!=(struct lista *)0)
	{
		printf("%i\n",cab->valor);
		cab=cab->prox;
	}
}
