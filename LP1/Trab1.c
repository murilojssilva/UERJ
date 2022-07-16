#include <stdio.h>
int n=0,fat;
int _contfat;
int fatorial (int n)
{
	_contfat++;
	if (n < 2)
		fat = 1;
	else
		fat = n * fatorial(n-1);
}
main()
{
	
	while (n<101)
	{
		_contfat=0;
		fat=0;		
		fatorial(n);
		printf("\nN = %d\nFatorial = %d\nNumero de chamadas = %d\n\n",n,fat,_contfat);
		n+=10;		
	}
}

