#include <stdio.h>
#define IN 1
#define OUT 0
main()
{
	char c;
	int status=OUT,i=0,k=0,j=0,max=80;
	char palavra[1000];
	while ((c=getchar())!=EOF)
	{
		if (c==' '||c=='\n'||c=='\t')
		{
			palavra[i]='\0';			
			if (max-i-1==0)
			{
				printf("%s",palavra);
				putchar(c);		
				putchar('\n');
				max=80;
			}
			else if (max-i==0)
			{
				printf("%s",palavra);
				putchar('\n');
				putchar(c);
				max=79;
			}
			else if (max-(i+1)<0)
			{								
				putchar('\n');
				printf("%s",palavra);
				putchar(c);
				max=79-i;
			}
			else if (max-1==0)
			{			
				putchar(c);
				putchar('\n');
				printf("%s",palavra);
				max=80-i;
			}
			else if (max==0)
			{
				putchar('\n');
				printf("%s",palavra);
				putchar(c);
				max=79-i;
			}
			else
			{
				printf("%s",palavra);
				putchar(c);
				max-=(i+1);
			}
			j=0;			
			i=0;
			status=OUT;
			char palavra[1000];
		}
		else
		{
			if (status=OUT)
			{
				status=IN;
			}
			palavra[i]=c;
			i++;
		}
		if (c=='\n')
			max=80;
	}
}

