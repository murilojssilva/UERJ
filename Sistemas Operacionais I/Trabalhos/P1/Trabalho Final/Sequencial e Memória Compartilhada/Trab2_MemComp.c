//Alunos: Camila Gusmão, Murilo de Jesus e Thainá Figueiredo
/*
No site é fornecida uma versão sequencial de um programa em C que informa quantos números primos existem entre dois inteiros positivos informados pelo usuário.
O trabalho consiste em paralelizar essa aplicação usando processos e memória compartilhadas, conforme visto no exemplo de somatório dos elementos de um vetor. O número de processos desejado também deve ser informado pelo usuário.
O trabalho é em trio (quem não tiver trio pode fazer individualmente) e apenas um membro da dupla precisa submeter o trabalho. Um zip contendo o código C e um relatório (ou comentários no código) explicando a implementação e uma medição do tempo sequencial e o tempo para 2 processos, considerando que a faixa fornecida é de 1 a 10 milhões (desejamos saber quantos primos existem entre 1 e 10 milhões). Tanto o código fonte quanto o relatório devem conter os nomes dos membros da dupla.
A versão sequencial do programa e o exemplo do somatório estão publicados no site.
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sys/shm.h>
#include <sys/ipc.h>

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
	int i,j=0;
	long int contp=0;
	pid_t pid;
	
	int numProc = atoi(argv[1]);
	long int inf=atoi(argv[2]);
    long int sup=atoi(argv[3]);	
	
	int sid = shmget(IPC_PRIVATE,sizeof(int)*numProc,IPC_CREAT|SHM_R|SHM_W); // cria a região de memória compartilhada e retorna um identificador para o segmento da região, que no caso é o sid

	printf("Numero de processos a ser criado: %d\n",numProc);
	
	pid = getpid();
	for(i=0;i<numProc;i++){
		
		pid=fork();
		
		if (pid < 0) { // teste de erro na criação do fork
			fprintf(stderr, "Fork falhou!\n");
			return 1;
		}
		else if (pid == 0) { // criação dos processos filhos
			int* somaVet = shmat(sid, NULL, 0); // anexa a região criada (sid) ao seu espaço de endereçamento do processo que deseja usá-la (somaVet)
			int tamBloco = sup-inf;
			int bloco = tamBloco/numProc;
			int start = (i*bloco)+inf;
			int end = ((i+1)==numProc)?sup:start+bloco;		
			
			for(i=inf;i<=sup;i++){
				if(ehPrimo(i)){
					contp++;
					#ifdef DEBUG
					printf("%ld, ",i);
					#endif
				}
			}
		
			somaVet[j]=contp; // armazena os resultados que foram do for anterior em uma posição do vetor de memória chamada somaVet
			shmdt(somaVet); // dexanexa a memória
		}
	
		else { // processo pai
			int* somaVet = shmat(sid, NULL, 0); // anexa a região criada (sid) ao seu espaço de endereçamento do processo que deseja usá-la (somaVet)
			for(j=0;j<numProc;j++){ // barreira, em que o pai aguarda que todos os seus processos filhos terminem seus processos
				wait(NULL);
			}

			int somaFinal=0;
			for (i=0; i<numProc; i++){ // faz a soma de todas as posições encontradas no vetor de memória e armazena o resultado no vetor somaFinal
				somaFinal+=somaVet[i];
			}

			shmdt(somaVet);
			printf("\nTotal de Primos=%d\n",somaFinal);
		}

		shmctl(sid, IPC_RMID, NULL); // usada para destruir a região de memória compartilhada (sid)
		return 0;
	}
}




