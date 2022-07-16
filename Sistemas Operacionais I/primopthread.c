// gcc primo.c -O3 -o primo -lm
// time ./primo 2 5000000

#include <pthread.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 4;

struct tdp
{
	//long int id;
	long int inf;
	long int sup;
};
struct tdp tdpri[N];

void *ehprimo(void *threadarg);

long int inf,sup,cp=0;

int main(int argc, char ** argv)
{
	//n = atoi(argv[1]);
	inf=atoi(argv[2]);
	sup=atoi(argv[3]);
	pthread_t td[N];
	pthread_attr_t attr;
	long int rc,tam,st,i;
	long int t;
	void* status;
	cp=1;
	
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	
	tam=sup-inf;
	st=0;
	for(t=0; t<n; t++)
	{
		printf("Criando a Thread %ld\n",t);
		//tdpri[t].id = t;
		tdpri[t].inf = st;
		tdpri[t].sup = st+tam;
		st = st + tam;
		rc = pthread_create(&td[t], &attr, ehprimo, (void *)&tdpri[t]);
		if (rc)
		{
			printf("ERROR; return code from pthread_create() is %ld\n", rc);
			exit(-1);
		}
	}
	for(t=0; t<n; t++)
	{
		rc = pthread_join(td[t], &status);
		if (rc)
		{
			printf("ERROR; return code from pthread_join() is %ld\n", rc);
			exit(-1);
		}
		printf("Main: completed join with thread %ld having a status of %ld\n",t,(long)status);
		cp = cp + (long) status;
    }
	printf("cont: %ld\n",cp);
	
	
	
	/*long int cp=0;
	for (i=inf; i<=sup; i++)
		if (ehprimo(i))
		{
			cp++;
			#ifdef DEBUG
			printf("%ld, ",i);
			#endif
		}
		*/
	printf("\nCount=%ld\n",cp);
	return 0;
}

void *ehprimo(void *threadarg)
{	
	struct tdp *tdprimo;
	tdprimo = (struct tdp *) threadarg;
	//id = tdp.id->id;
	inf = tdprimo.inf->inf;
	sup = tdprimo.sup->sup;
	
	printf("Numeros de primos %ld -> %ld\n", inf, sup);
	long int i,j,lim;
	
	for (j=inf+1;j<=sup;j=j+2)
	{
		if (j==1) continue;
		lim = (int)sqrt(j); 
		int primo = 1;
		for (i=3;i<=lim;i+2)
		{
			if ((j%i)==0)
			{
				primo=0;
				break;
			}
		}
		if (primo) cp++;
	}
	pthread_exit((long int*) cp);
	//return primo;
}
