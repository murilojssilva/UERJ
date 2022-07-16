#include <stdio.h>
#define IN 1
#define OUT 0
main()
{
	char c;
	int nc,nl,np,nt,ne,state=OUT;
	for (nc=0;(c=getchar())!=EOF;nc++)
	{
		if (c=='\n')
			nl++;
		if (c=='\t')
			nt++;
		if (c==' ')
			ne++;
		if (c == ' ' || c == '\n' || c == '\t')
			state=OUT;
		else if (state==OUT)
			state=IN;
			np++;
	}
	printf("\nNúmero de linhas: %d\nNúmero de palavras: %d\nNúmero de caracteres: %d\nNúmero de espaços: %d\nNúmero de tabulações: %d",nl,np,nc,ne,nt);
}
