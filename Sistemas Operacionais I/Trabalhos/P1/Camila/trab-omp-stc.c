/*
No caso da versao OpenMP, voce devera usar compilacao condicional (com #ifdef _OPENMP) conforme visto nos exemplos em sala de aula. 
A implementacao em OpenMP deve usar a diretiva parallel for com reducao. 
Voce devera entregar 1 zip com os dois programas e os tempos usando oversubscription, escalomento "static", "dynamic" e "guided".
*/
//gcc trab3-omp-dyn.c -o -lm -fopenmp  trab3-omp-dyn
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
	int numT,inf,sup,i,cont=0;
	numT = atoi(argv[1]);
	inf = atoi(argv[2]);
	sup = atoi(argv[3]);
	
	#ifdef _OPENMP
	printf("entrei\n");
	omp_set_num_threads(numT);
	#endif
	
	#pragma omp parallel for schedule(static, 1000) reduction(+:cont)
	for(i=inf;i<=sup;i++){
		if(ehPrimo(i)) 
			cont++;
	}
	printf("Total de primos: %d",cont);
	
	return 0;
}