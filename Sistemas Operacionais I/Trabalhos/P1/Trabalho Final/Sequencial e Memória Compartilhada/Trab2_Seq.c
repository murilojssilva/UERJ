//Alunos: Camila Gusmão, Murilo de Jesus e Thainá Figueiredo
/*
No site é fornecida uma versão sequencial de um programa em C que informa quantos números primos existem entre dois inteiros positivos informados pelo usuário.
O trabalho consiste em paralelizar essa aplicação usando processos e memória compartilhadas, conforme visto no exemplo de somatório dos elementos de um vetor. O número de processos desejado também deve ser informado pelo usuário.
O trabalho é em trio (quem não tiver trio pode fazer individualmente) e apenas um membro da dupla precisa submeter o trabalho. Um zip contendo o código C e um relatório (ou comentários no código) explicando a implementação e uma medição do tempo sequencial e o tempo para 2 processos, considerando que a faixa fornecida é de 1 a 10 milhões (desejamos saber quantos primos existem entre 1 e 10 milhões). Tanto o código fonte quanto o relatório devem conter os nomes dos membros da dupla.
A versão sequencial do programa e o exemplo do somatório estão publicados no site.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ehprimo(long int n);

int main(int argc, char ** argv)
{
	long int i;
	long int cp=0;
	long int inf=atoi(argv[1]);
	long int sup=atoi(argv[2]);
	for (i=inf; i<=sup; i++)
		if (ehprimo(i))
		{
			cp++;
			#ifdef DEBUG
			printf("%ld, ",i);
			#endif
		}
	printf("\nCount=%ld\n",cp);
	return 0;
}

int ehprimo(long int n)
{
	int primo = 1;
	long int i;
	for (i=2;i<sqrt(n+1);i++)
	{
		if ((n%i)==0)
		{
			primo=0;
			break;
		}
	}
	return primo;
}
