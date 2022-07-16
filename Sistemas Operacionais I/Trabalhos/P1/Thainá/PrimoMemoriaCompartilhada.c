//Alunos: Camila Gusmão, Murilo de Jesus e Thainá Figueiredo


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




