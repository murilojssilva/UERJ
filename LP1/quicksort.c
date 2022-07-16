#include <stdio.h>
int aux,t,e,d,i,j;
int Troca(int i,j)
{
	i=aux;
	i=j;
	j=aux;
}
int Particao (int e,d,i,j)
{
	i=e;
	j=d;
	t=V[(e+d)/2];
	while (i<=j)
	{
		while (V[i]<t)
			i++;
		while (V[j]>t)
			j--;
		if (i<=j)
		{
			Troca(i,j);
			i++;
			j--;
		}
	}
}
int Quicksort (e,d)
{
	if (d>e)
	{
		Particao (e,d,i,j);
		Quicksort (e,j);
		Quicksort (i,d);
	}
}
main()
{
	Quicksort(e,d);
}
