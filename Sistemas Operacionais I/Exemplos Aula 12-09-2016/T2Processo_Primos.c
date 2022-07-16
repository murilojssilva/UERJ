// gcc T2Processo_Primos.c -O3 -o T2Processo_Primos -lm
// c

#include <errno.h>
#include <sys/types.h>

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

int main(int argc, char ** argv)

{
	
	long long int num = atoi(argv[1]);
	pid_t prim[num],ret;
	int i,j,k,aux=0,cp=0;

	for(i=1;i<=num;i++)	prim[i]=i;
	for (i=1;i<num;i++)

	{
		if (prim[i]<0)
		{
			perror("impossivel criar um filho");
			exit(-1);
		}
		else if (prim[i] != 0) 
		{
			for (j=2;j<(num/2);j++)
			{
				if (prim[i]%j < 0)

				{
					fprintf(stderr, "Erro para n = %d\n",prim[i]);

					exit(0);
				}
		
				else if (prim[i]%j == 0 && prim[i] > j)

				{		
					aux=1;
					break;
				}

				else
				{
					printf("Filho %d em execucao",getpid());
					wait();
				}
			}
			if (aux==0)
			{
				cp++;
			}
			aux=0;
		}
		else
		{
			printf("De 1 ate %d tem %d primos",prim[i],cp);
			ret=waitpid(prim[i],NULL,NULL);
			if (ret!=prim[i])
			{
				//printf("Waitpid: %s\n",strerror(errno));
				printf("Erro!!\n");
				exit(1);
			}
		}
	}	
	printf("\nNumero de primos: %d\n",cp);

	fflush(stdout);
	return 0;
}