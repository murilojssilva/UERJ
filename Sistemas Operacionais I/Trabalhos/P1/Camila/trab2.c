/*
TRABALHO 2
No site é fornecida uma versão sequencial de um programa em C que informa quantos números primos existem entre dois inteiros positivos informados pelo usuário.
O trabalho consiste em paralelizar essa aplicação usando processos e memória compartilhadas, conforme visto no exemplo de somatório dos elementos de um vetor. 
O número de processos desejado também deve ser informado pelo usuário. 
Um zip contendo o código C e um relatório (ou comentários no código) explicando a implementação e uma medição do tempo sequencial e o tempo para 2 processos, 
considerando que a faixa fornecida é de 1 a 10 milhões (desejamos saber quantos primos existem entre 1 e 10 milhões). 
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int ehPrimo(long num){
	long i;
	if(num<=1)return 0;
	for(i=2;i<=sqrt(num+1);i++){
		if(num%i==0)return 0;
	}
	return 1;	
}

int main(int argc,char* argv[]){
	int n,i,j,num;
	pid_t pid;
	
	n = atoi(argv[1]);
	//fizemos com vetor, mas vetores tambem sao replicados no fork
	//int* cont = (int*) malloc(sizeof(int)*n);
	//for(j=0;j<n;(*(cont+(j++))= 0)); //ZERAR O VETOR for(j=0;j<n;j++) (cont+j)*= 0;
	
	int sid = shmget(IPC_PRIVATE,sizeof(int)*n,IPC_CREAT|SHM_R|SHM_W);
	
	printf("Numero de processos filhos a ser criado: %d\n",n);
	
	for(i=0;i<n;i++){
		pid=fork();
		if(!pid) //se n for o pai n crio processos
			break;
	}
	
	num = atoi(argv[2]);
	//tblc = num/nprocs
	//p1(1,tblc)
	//p2(tblc+1,2*tblc)
	//pi((i*tblc)+1,(i+1)*tblc)
	int tamBloco = num/(n+1);
	int ini, fim;
	ini = (i)*tamBloco+1;
	//fim = (i+1)*tamBloco;
	fim=(i==n)? num :(i+1)*tamBloco;
	
	
	//for(a;b;c)
		
	//a
	//while(b){
	//	c
	//	resto
	//}
	int* cont = shmat(sid, NULL, 0);
	for(j=ini;j<=fim;j++){
		*(cont+i) += ehPrimo(j);
		//printf("f: %d is p? %d\n",j,ehPrimo(j));
	}	
	//shared memory get(shmget)
	//shared memory attach(shmat)
	if(pid){
		for(j=0;j<n;j++) wait();
		int contador=0;
		for(j=0;j<=n;j++) 
				contador+= *(cont+j);
		printf("Temos %d primos de 0 a %d\n",contador,num);
	}
	shmdt(cont);// analogo ao free

	return 0;
}
