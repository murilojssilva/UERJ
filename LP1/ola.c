#include <stdio.h>
#define IN 1
#define INL 1
#define OUTL 0
#define OUT 0
main()
{
	char c;
	int state,i,j,a;
	int palavra[1000];
	a=0;
	state=OUT;
	for (i=0;i<=1000;i++)
		palavra[i]='\b';
	while ((c=getchar())!=EOF)
	{
		if (c==' '||c=='\n'||c=='\t')
		{					
			printf("%s ", palavra[a]);			
			state=OUT;
			a++;
		}
		else
			palavra[a]+=c;
		if (palavra[a]!= ' ')
			state=IN;
	}
}
