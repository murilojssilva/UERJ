// gcc proc.c -O3 -o primo -lm
// time ./proc 4 1 10000000
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int ehprimo(long int n);
int main(int argc, char ** argv)
{
	long int i;
	long int cp=0,ct=0;
	long int n=atoi(argv[1]);
	long int inf=atoi(argv[2]);
	long int sup=atoi(argv[3]);
	long int rad;
	rad=(sup-inf)/n;
	pid_t pid;
	
	for (i=0;i<n;i++)
	{
		pid=fork();
		if (pid < 0)
		{
			fprintf(stderr, "Fork falhou para n = %ld\n", n);
			exit(1);
		}
		else if (pid == 0)
		{
			long int j;
			for (j=inf+(rad*i)+i; j<=inf+(rad*(i+1))+(i); j++)
			{
				if (ehprimo(j) && j!=1 && j<=sup)
				{
					//printf("%ld ",j);
					cp++;
					ct+=cp;
				}
			}
			break;
		}
	}
	if (pid>0)
	{
		for (i=0; i<n; i++)	waitpid(pid);
		fflush(stdout);
		exit(2);
	}
	ct+=cp;	
	printf("Count=%ld\n",cp);
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
