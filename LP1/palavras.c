#include <stdio.h>
#define IN 1
#define OUT 0
main()
{
	
	int c,status,i=0,palavra,tamanho;
	tamanho=80;
	status=OUT;
	palavra='\b';
	while ((c=getchar())!=EOF)
	{
		if (c==' '||c=='\n'||c=='\t')
		{
			palavra=' ';
			if (tamanho-i<0)
			{
				status=OUT;
				printf("\n");
				tamanho=80;
			}
			else
			{
				putchar(palavra);
				//printf("%s",palavra);
				tamanho-=i;
				i=0;
			}
		}
		else 
			if (status==OUT)
			{
				status=IN;
			}
			palavra+=c;
			i++;
	}
}

