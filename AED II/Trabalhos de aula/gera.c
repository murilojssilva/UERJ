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
		Comb(np,q);
}
/*
Saída: 1 2 3 1 2 4 1 2 5 1 2 6 1 2 7 1 2 8 1 2 9 1 2 10 1 2 11 1 2 12 1 2 13 1 2 14 1 2 15 1 2 16 1 2 17 1 2 18 1 2 19 1 2 20 1 2 21 1 2 22 1 2 23 1 2 24 1 2 25 1 2 26 1 2 27 1 2 28 1 2 29 1 2 30 1 2 31 1 2 32 1 2 33 1 2 34 1 2 35 1 2 36 1 2 37 1 2 38 1 2 39 1 2 40 1 2 41 1 2 42 1 2 43 1 2 44 1 2 45 1 2 46 1 2 47 1 2 48 1 2 49 1 2 50 1 2 51 1 2 52 1 2 53 1 2 54 1 2 55 1 2 56 1 2 57 1 2 58 1 2 59 1 2 60 1 2 61 1 2 62 1 2 63 1 2 64 1 2 65 1 2 66 1 2 67 1 2 68 1 2 69 1 2 70 1 2 71 1 2 72 1 2 73 1 2 74 1 2 75 1 2 76 1 2 77 1 2 78 1 2 79 1 2 80 1 2 81 1 2 82 1 2 83 1 2 84 1 2 85 1 2 86 1 2 87 1 2 88 1 2 89 1 2 90 1 2 91 1 2 92 1 2 93 1 2 94 1 2 95 1 2 96 1 2 97 1 2 98 1 2 99 1 2 100 1 2 101 1 2 102
*/