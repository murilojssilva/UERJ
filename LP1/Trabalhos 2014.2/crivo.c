#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
//Crivo de Eratóstenes
 
void ApagaMultiplosDoPrimo(int *, int *, int , int);
 
int main()
{
    int i=2, N=0, raiz;
    scanf("%d", &N);
    if (N>1000 || N<0)
	printf("Número inválido\n");
    else
    {
	    raiz = sqrt (N);
	    int *V, *posV;
	    V=(int*) malloc((N+2)*sizeof (int));
	    posV=V+2;
	    *V=0;
	    *(V+1)=0;
	    *(V+N+1)=-1;
	    while (*posV!=-1)
		{
			(*posV)=1;
			(*posV++);
		}
	    posV=V+2;
	    while (i <= raiz)
	    {
		if (*posV-- == 1)
		{
		    ApagaMultiplosDoPrimo(V, posV, i , N);
		}
		posV++;
		i++;
	    }
	    //posV=V+((N/10000)*9999); //Para limitar a faixa de números apresentados e, com isso, reduzir o tempo
	    //i=(posV-V);
	    for (i=0; i<N; i++)
	    {
		if (*posV==1)
			printf("%ld ", (posV-V));
		posV++;
	    }
	    free(V);
	}
}
void ApagaMultiplosDoPrimo(int *V, int* posV, int i , int N)
{
    posV=V+(i*i);
    while ((posV-V)<=N)
    {
        if ((posV-V)%i == 0) *posV = 0;
        posV=posV+i;
    }
}
/*
O Crivo de Eratóstenes é um algoritmo que provê um método simples e prático para se encontrar todos os números  primos menores que um certo valor limite N. Para implementá-lo na linguagem C precisamos de um array. Cada posição deste array pode conter dois valores, 1 (um), caso o número correspondente ao índice do array seja primo, e 0 (zero), caso não. O array deve ser inicializado com todos os valores dos elementos iguais a 1. As exceções são os valores dos índices 0 e 1 do array, que são inicializados com zero uma vez que sabe-se de antemão que os números zero e um não são primos. 
A implementação do algoritmo é iterativa, percorrendo o array de números dos índices 2 até N. Para cada número primo encontrado todos os seus múltiplos são marcados com não primos. Ao final do algoritmo, sobram apenas com valores iguais a um os índices do vetor relativos aos números primos. 
Entrada: Seu programa deve receber através do teclado o valor limite N. (N não será em hipótese alguma maior do que 1000)
Saída: Seu programa deve imprimir na tela os valores dos números primos menores que N separados de um caracter espaço.
Restrições:
1) O array usado para o cálculo do crivo deve ser alocado dinamicamente em função do tamanho da entrada.
2) Os laços da sua implementação do ALGORITMO DE CÁLCULO DO CRIVO DE ERATÓSTENES devem ter o menor número de iterações possível.
3) Todas as iterações com o array devem obrigatoriamente utilizar aritmética de apontadores.
*/
