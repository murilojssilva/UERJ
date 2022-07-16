#include<stdio.h>
#include<stdlib.h>

int ehPrimo(long num){
	long i;
	if(num<=1)return 0;
	for(i=2;i<num;i++){
		if(num%i==0)return 0;
	}
	return 1;	
}

int main(int argc,char* argv[]){
	int i,j,num;
	num = atoi(argv[1]);	
	pid_t pid; 
	int numProc=4, j;
	for(j=0;j<numProc-1;j++){ 
		pid=fork();
		if(!pid) //se n for o pai, ele sai, isto e, n cria processos
			break;
	}
	
	int tamBloco = num/numProc;
	int cont1=0,cont2=0,cont3=0,cont4=0;
	int * proc = (int) malloc(sizeof(int)*numProc);
	//zerar vetor//trocar parte de baixo
	switch(i){
		 case 0: for(i=0;i<num;i++) if(ehPrimo(i)) cont1++; break;
		 case 1: for(i=0;i<num;i++) if(ehPrimo(i)) cont2++; break;
		 case 2: for(i=0;i<num;i++) if(ehPrimo(i)) cont3++; break;
		 case 3: for(i=0;i<num;i++) if(ehPrimo(i)) cont4++; break;		
	}
	int cont = cont1+cont2+cont3+cont4; //ERRO: Criar  um vetor onde cada cont fica na posicao do seu processo(o indice e o id do meu processo)
	printf("Total de primos: %d",cont);
	return 0;
}