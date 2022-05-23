/*
Nome: Murilo de Jesus Santos Silva
EXC 06
N = 100 + x e q = x, com x = 24 mod 4 + 3 = 3
*/
#include <stdio.h>
int i,n=103,np=0,q=3,x=0;
int P[200];
int Comb (int n, int q);
main()
{
		P[0]=0;
		while (x<200)
			Comb(np,q);
}
Comb (int np,int q)
{
	for (i=1;i<n;i++)
	{
		if (i > P[np])
		{		
			np++;
			P[np]=i;
			if (np == q)
			{
				printf("%d ",P[np]);
				x++;
			}
			else
			{
				Comb(np,q);
			}
			np--;
		}
	}
}
