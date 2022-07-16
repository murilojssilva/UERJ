#include <stdio.h>
#define INICIAL -10
#define FINAL 100
#define INCRE 10
main()
{
	int cels=INICIAL;
	float fahr;
	while (cels<FINAL+1)
	{	
		fahr=1.8*cels+32;
		printf("\nCelsius %dºC\tFahrenheit %.2f\n",cels,fahr);
		cels+=INCRE;
	}
}
