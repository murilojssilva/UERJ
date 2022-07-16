#include <stdio.h>
#define IN 1
#define OUT 0
main()
{
	char c;
	int status,j,i=0,k=0,max;
	char palavra[100];
	max=80;
	status=OUT;
	for (j=0;j<100;j++)
		palavra[j]=' ';
	while ((c=getchar())!=EOF)
	{
		if (c==' '||c=='\n'||c=='\t')
		{
			for (j=0;j<=100;j++)
				palavra[j]=' ';
			if (max-i<0)
			{
				status=OUT;
				printf("\n");
				max=80;
			}
			else
			{
				while (k<i)
				{
					putchar(palavra[k]);
					k++;
				}
				max-=i;
				char palavra[100];
				k=0;
				i=0;
			}
		}
		else 
			if (status==OUT)
			{
				status=IN;
			}
			palavra[i]=c;
			i++;
	}
}

