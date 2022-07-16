/*
No caso da versão OpenMP, você deverá usar compilação condicional (com #ifdef _OPENMP) conforme visto nos exemplos em sala de aula. 
A implementação em OpenMP deve usar a diretiva parallel for com redução. 
Você deverá entregar 1 zip com os dois programas e os tempos usando oversubscription, escalomento "static", "dynamic" e "guided".
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int ehPrimo(long num){
	long i;
	if(num<=1)return 0;
	for(i=2;i<=sqrt(num+1);i++){
		if(num%i==0)return 0;
	}
	return 1;	
}

int main(int argc,char* argv[]){
	int i, num, cont=0;
	num=atoi(argv[1]);
	#pragma omp parallel for reduction(+:cont)
	for(i=0;i<num;i++){
		if(ehPrimo(i)) 
			cont++;
	}
	printf("Total de primos: %d",cont);
	return 0;
}