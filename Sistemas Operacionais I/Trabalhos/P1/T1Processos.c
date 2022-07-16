#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	pid_t pid[10];
	int i;
	for(i=0;i<10;i++)	pid[i]=0;
	for (i=0;i<10;i++)
	{
		pid[i] = fork();
		if (pid[i] < 0)
		{ //erro
			fprintf(stderr, "Fork falhou para n = %d\n", n);
			exit(1);
		}
		else if (pid[i] == 0)
		{ //processo filho
			printf("Sou o filho - %d.\n", getpid());
			fflush(stdout);
			break;
		}
	}
	if (pid[9]>0)
	{ //processo pai
		for (i=0; i<10; i++)	waitpid(pid[i]);
		fflush(stdout);
		printf("Filhos terminaram!\n");
	}
	return 0;
}
