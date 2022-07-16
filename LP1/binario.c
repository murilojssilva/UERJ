#include <stdio.h>
main()
{	
	int num,numero,resto=0,i=0,j,k,aux;
	char binario[100000],c;
	printf("Digite um numero: ");
	scanf("%d",&num);
	num=numero;
	while (num>0)
	{
		resto=num%2;
		binario[i]=resto;
		resto=0;
		num=num/2;
		i++;
	}
	k=i;
	for (j=0;j<=i;j++)
	{
		aux=binario[j];
		binario[j]=binario[i];
		binario[i]=aux;
		i--;
	}
	for (j=0;j<=k;j++)
		printf("%d",binario[j]);
	printf("\ni - %d\nnum - %d\nnumero - %d",i,num,numero);
}
