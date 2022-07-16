// gcc proc.c -O3 -o proc -lm
// time ./proc 4 1 10000000
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int ehprimo(long int n);
int main(int argc, char ** argv)
{
	long int i,j;
	int n=atoi(argv[1]);
	long int num=atoi(argv[2]);
	
	char *path="nome_de_arquivo_existente" ;
	//long int sid = shmget(IPC_PRIVATE,sizeof(long int)*(n),SHM_R|SHM_W|IPC_CREAT);
	//printf("%ld\n",sizeof(int)*n);
	int sid = shmget(IPC_PRIVATE,sizeof(int)*n,IPC_CREAT|SHM_R|SHM_W);
	
	
	if (sid == -1)
	{
		printf("main: shmget() failed\n");
		return -1;
	}
	
	
	int* cont = shmat(sid, NULL, 0);
	long int tamBloco = num/(n+1);
	long int ini, fim;
	
	 
	ini = (i)*tamBloco+1;
	fim=(i==n)? num :(i+1)*tamBloco;
	
	pid_t pid;
	for(j=ini;j<=fim;j++)
	{
		*(cont+i) += ehprimo(i);
	}
	
	if (pid)
	{
		int cp=0;
		for (j=0; j<n; j++)		waitpid(pid);
		for(j=0;j<=n;j++) 
				cp+= *(cont+j);
		printf("Temos %d primos de 0 a %ld\n",cp,num);
	}
	shmdt(cont);
	return 0;
}
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
