// gcc T2Processo_Primos.c -O3 -o T2Processo_Primos -lm
// time ./T2Processo_Primos 300

#include <sys/types.h>

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

int main(int argc, char ** argv)

{
	
	long long int num = atoi(argv[1]);
	pid_t prim[num];
	int i,j,k,aux=0,cp=0;

	for(i=1;i<=num;i++)	prim[i]=i;
	for (i=1;i<num;i++)

	{
		if (prim[i] != 1) 
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

			}
			if (aux==0)
			{
				cp++;
			}
			aux=0;
		}
	}	
	printf("\nNumero de primos: %d\n",cp);

	fflush(stdout);
	return 0;
}