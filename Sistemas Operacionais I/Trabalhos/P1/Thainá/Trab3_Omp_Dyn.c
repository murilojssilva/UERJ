/*
Alunos: Camila Gusmão, Murilo de Jesus e Thainá Figueiredo
TRABALHO 3
Elaborar duas versões do programa contador de primo (o mesmo do trabalho 1): uma versão usando pthreads e outra usando OpenMP. Nas duas versões, o programa deverá receber, por linha de comando, os limites inferior e superior e o número de threads desejadas. No caso da versão OpenMP, você deverá usar compilação condicional (com #ifdef _OPENMP) conforme visto nos exemplos em sala de aula. A implementação em OpenMP deve usar a diretiva parallel for com redução.
No caso da versao OpenMP, voce devera usar compilacao condicional (com #ifdef _OPENMP) conforme visto nos exemplos em sala de aula. 
A implementacao em OpenMP deve usar a diretiva parallel for com reducao. 
Voce devera entregar 1 zip com os dois programas e os tempos usando oversubscription, escalomento "static", "dynamic" e "guided".
*/
//gcc Trab3_Omp_Dyn.c -o Trab3_Omp_Dyn -lm -fopenmp  

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int ehPrimo(long int n){  //cálculo dos primos da mesma forma que apresentado no trabalho sequencial 
	int primo = 1;
	long int i;
	for (i=2;i<sqrt(n+1);i++){
		if ((n%i)==0){
			primo=0;
			break;
		}
	}
	return primo;
}

int main(int argc,char* argv[]){
	long int i;
	long int contp=0;
	long int inf=atoi(argv[1]);
	long int sup=atoi(argv[2]);

	#ifdef _OPENMP  //só passará nessa essa condição caso na linha de comando seja executada -fopenmp
		omp_set_num_threads(atoi(argv[3]));  //controle do número de threads
	#endif

	#pragma omp parallel for schedule(dynamic, 1000) reduction(+:contp) //cada thread vai ter uma cópia da variável contp, fará a soma local com sua cópia e, ao sair da execução paralela, as somas locais vão ser adicionadas na variável global.

	for(i=inf;i<=sup;i++){
		if(ehPrimo(i)) 
			contp++;
	}
	printf("Total de primos: %ld\n",contp);
	
	return 0;
}
