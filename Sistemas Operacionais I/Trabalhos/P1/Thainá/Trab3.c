/*
TRABALHO 3
Elaborar duas versões do programa contador de primo (o mesmo do trabalho 1): uma versão usando pthreads e outra usando OpenMP. Nas duas versões, o programa deverá receber, por linha de comando, os limites inferior e superior e o número de threads desejadas. No caso da versão OpenMP, você deverá usar compilação condicional (com #ifdef _OPENMP) conforme visto nos exemplos em sala de aula. 
A implementação em OpenMP deve usar a diretiva parallel for com redução. 
Você deverá entregar 1 zip com os dois programas e os tempos usando oversubscription, escalomento "static", "dynamic" e "guided".
*/
//gcc trab3.c -o trab3 -lm -lpthread
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>

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


typedef struct a{//criação de uma struct que receberá 3 parâmetros
	int ini;
	int fim;
	int cont;
}argumento;

void* fc(void* arg){//verificando se os parâmetros que estão entre ini e fim são primos
	int j;
	argumento x = *((argumento*) arg);//criação de uma variável do tipo struct a
	
	for(j=x.ini;j<=x.fim;j++){
			x.cont += ehPrimo(j);
			//printf("f: %d is p? %d\n",j,ehPrimo(j));
	}
	printf("cont x: %d-%d has %d\n",x.ini,x.fim, x.cont);
	return x.cont; //return 0;
}

int main(int argc,char* argv[]){
	pthread_t tid;
	int numT,inf,sup,tamBloco,i,contador=0;
	numT = atoi(argv[1]);
	inf = atoi(argv[2]);
	sup = atoi(argv[3]);	
	
	argumento* listaCont = (argumento*) malloc(sizeof(argumento)*numT);
	pthread_t* vetTid = (pthread_t*) malloc(sizeof(pthread_t)*numT);
	
	tamBloco = (sup-inf+1)/numT;
	
	for(i=0;i<numT;i++){
		(listaCont+i)->cont = 0;
		(listaCont+i)->ini = inf+(tamBloco*i); // 10 +0 = 10 ; 10 + 10 = 20 ; 10 + 10*2 = 10+20 = 30
		(listaCont+i)->fim = (i==numT-1)? sup : inf+(tamBloco*(i+1))-1;		
	}
	//*(listaCont+i).cont = 0; solução1: (*(listaCont+i)).cont = 0;  	a->b IGUAL A: (*a).b linha64 feito de outra forma

	
	for(i=0;i<numT;i++){		
		pthread_create((vetTid+i),NULL,fc,(listaCont+i));		
	}
	
	for(i=0;i<numT;i++){
		void* ret;
		//DECLARACAO: int pthread_join(pthread_t thread, void **retval);
		pthread_join(*(vetTid+i),&(ret)); //ANTES: pthread_join(*(vetTid+i),NULL);
		
		//printf("%d\n",(*(listaCont+i)).ini);
		contador +=(int) ret;	//contador +=(*(listaCont+i)).cont;
	}
	printf("Temos %d numeros primos no intervalo de %d a %d\n",contador,inf,sup);
	return 0;
}
