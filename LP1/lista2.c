#include <stdio.h>
struct lista{
	int valor;
	struct lista *prox;
};
struct lista *procurarValor(struct lista *pLista,int valor)
{
	while (pLista!=(struct lista *)0)
	{
		if (pLista->valor==valor)
			return (pLista);
		else
			pLista=pLista->prox;
	}
	return (struct lista *)0;
}
int main()
{
	struct lista *procurarValor(struct lista *pLista,int valor);
	struct lista m1,m2,m3;
	struct lista *result,*cab=&m1;
	int valor;
	m1.valor=5;
	m2.valor=10;
	m3.valor=15;
	m1.prox=&m2;
	m2.prox=&m3;
	m3.prox=(struct lista *)0;
	scanf("%d",&valor);
	result = procurarValor(cab,valor);
	if (result==(struct lista *)0)
		printf("Valor não encontrado\n");
	else	printf("Valor %d encontrado\n",result->valor);
}
