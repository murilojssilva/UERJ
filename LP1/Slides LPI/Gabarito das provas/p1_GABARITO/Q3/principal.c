#include <stdio.h>
#include <auxiliar.h>

int main(void)
{
	char caminho[200];
	int n;
	printf("Digite o caminho do arqivo: ");
	gets(caminho);

	printf("Digite um inteiro: ");
	scanf("%d", &n);
	
	printf("Quantidade de linhas inseridas = %d\n", wrap(caminho,n));
}
