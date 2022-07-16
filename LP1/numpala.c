#include <stdio.h>
#define IN 1
#define OUT 0
main()
{
	char c;
	int state=OUT,np;
	while ((c=getchar())!=EOF)
	{
		if (c==' '|| c=='\t'||c=='\n')
			state=OUT;
		else if (state=OUT)
			state=IN;
			np++;
	}
	printf("Número de palavras: %d",np);
}
