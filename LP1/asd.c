/*
Nome: Murilo de Jesus Santos Silva
EXC 06
N = 100 + x e q = x, com x = 24 mod 4 + 3 = 3
*/
#include <stdio.h>
int i,n=103,np=0,q=3,x=0,f;
int P[103];
int Comb (int np,int q)
{
	for (i=1;i<n;i++)
	{
		if (i > P[np])
		{		
			np++;
			P[np]=i;
			if (np == q)
			{
				x++;
				if (x<200)
				{
					for(f = 1;f <= np;f++) 
					{
					printf("%d ",P[f]);  
					}
				}
			}
			else
			{
				Comb(np,q);
			}
			np--;
		}
	}
}
main()
{
		P[0]=0;
		while (x<200)
			Comb(np,q);
}
