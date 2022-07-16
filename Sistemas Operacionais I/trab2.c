#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sys/shm.h>
#include <sys/ipc.h>

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

int main(int argc,char* argv[])
{
	int n,i,j,num;
	pid_t pid;
	
	n = atoi(argv[1]);
	num = atoi(argv[2]);
	//inf = atoi(argv[2]);
	//sup = atoi(argv[3]);
	
	printf("Numero de processos filhos a serem criados: %d\n",n);
	printf("N = %d\n",num);
	//(IPC_PRIVATE,sizeof(int)*2, SHM_R|SHM_W|IPC_CREAT
	int sid = shmget(IPC_PRIVATE,sizeof(int)*(n*n),SHM_R|SHM_W|IPC_CREAT);
	printf("SID = %d\n",sid);
	
	if (sid == -1)
	{
		printf("main: shmget() failed\n");
		return -1;
	}
	
	for(i=0;i<n;i++)
	{
		pid=fork();
		if(!pid) //se n for o pai n crio processos
			break;
	}
	int tamBloco = (num)/(n+1);
	int ini, fim;
	ini = (i)*tamBloco+1;
	//fim = (i+1)*tamBloco;
	fim=(i==n)? (num) :(i+1)*tamBloco;
	int* cont = shmat(sid, NULL, 0);
	for(j=ini;j<=fim;j++)		*(cont+i) += ehprimo(j);
	if(pid){
		for(j=0;j<n;j++) wait();
		int contador=0;
		for(j=0;j<=n;j++) 
				contador+= *(cont+j);
		printf("Temos %d primos de 0 a %d\n",contador,num);
	}
	shmdt(cont);
}
