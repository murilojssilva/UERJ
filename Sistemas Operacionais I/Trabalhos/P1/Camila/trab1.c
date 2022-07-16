/*
TRABALHO 1
Fazer um programa em C para Linux que receba como argumento de linha de comando um inteiro N e, usando a chamada fork, crie N processos filhos. 
O pai deve aguardar o término de todos os filhos e imprimir seu PID. Os filhos devem apenas imprimir seus PIDs.
*/

//int argc = qtde de argumentos recebidos
//char* argv[] = vetor de ponteiros char, onde cada posição do vetor guarda a referência de uma palavra
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc,char* argv[]){
	int n,i;
	pid_t pid;
	
	n = atoi(argv[1]);
	printf("Numero de processos filhos a ser criado: %d\n",n);
	
	for(i=0;i<n;i++){
		pid=fork();
		if(!pid) //se n for o pai n crio processos
			break;
	}
	if(pid == 0) printf("%d\n",getpid());
	else{
		for(i=0;i<n;i++)	wait();
		printf("%d\n",getpid());
	}

	return 0;
}