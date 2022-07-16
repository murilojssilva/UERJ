#include <stdio.h>
#define INICIAL -10
#define FINAL 100
#define INCRE 10
main()
{
	int cels;
	float fahr;
	for (cels=INICIAL;cels<=FINAL;cels=cels+INCRE)
	{
		fahr=1.8*cels+32;
		printf("\nCelsius %dºC\tFahrenheit %.2f\n",cels,fahr);
	}
}
