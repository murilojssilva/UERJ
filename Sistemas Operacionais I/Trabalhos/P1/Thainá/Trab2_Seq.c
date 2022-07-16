#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ehprimo(long int n);

int main(int argc, char ** argv)
{
	long int i;
	long int cp=0;
	long int inf=atoi(argv[1]);
	long int sup=atoi(argv[2]);
	for (i=inf; i<=sup; i++)
		if (ehprimo(i))
		{
			cp++;
			#ifdef DEBUG
			printf("%ld, ",i);
			#endif
		}
	printf("\nCount=%ld\n",cp);
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
