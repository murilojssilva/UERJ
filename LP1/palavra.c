#include <stdio.h>
#define IN 1
#define OUT 0
main()
{
	char c;
	int status,j=0,i=0,k=0,max;
	char palavra[1000];
	max=80;
	status=OUT;
	while ((c=getchar())!=EOF)
	{					
		if (c==' '||c=='\n'||c=='\t')
		{
			max-=i;
			max--;
			j++;
			if (max-j<0)
			{			
				putchar(c);
				putchar('\n');
				max=80;
			}
			else if (max-i==0)
			{
				putchar('\n');
				putchar(c);
				max=79;
			}
			else
				putchar(c);
			k=0;
			i=0;
			j=0;
			char palavra[1000];
			status=OUT;
		}
		else
		{
			j++;
			if (status==OUT);
				status=IN;
		}
		if (status=IN)
		{						
			palavra[i]=c;
			i++;
			putchar(c);
		}
	}
}
