#include<stdio.h>
main()
{
	double cels,fa=0;
	while (fa<301)
	{
		cels=(fa-32)*5/9;
		printf("\nFarenheit: %.3lf F\tCelsius: %0.3lf ºC\n",fa,cels);
		fa+=20;
	}
}
