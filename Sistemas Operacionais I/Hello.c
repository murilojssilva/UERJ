#include <stdio.h>
int main (void)
{
	#pragma omp parallel
	{
		printf("Oi, mundo"\n);
	}
	return 0;
}