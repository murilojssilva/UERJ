#include <stdio.h>
#define IN 1
#define OUT 0
main()
{
	char c;
	int palavra[100];
	int i,a=0,state;
	for (i=0;i<100;i++)
		palavra[i]='\b'
	while ((c=getchar())!=EOF)
	{
		if (c==' '||c=='\n'||c=='\t)
			palavra[a++];
			putchar(' ');
			state=OUT;
		else
			palavra[a]+=c;
		if (state =cx
	}
	for (i=0;i<=a;i++)
		printf("%d",palavra[a]);
}
