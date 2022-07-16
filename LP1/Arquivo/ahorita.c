#include <stdio.h>
#include <string.h>
void main()
{
	FILE *file;
	file=fopen("Ahorita.txt","r");
	int tot=0,imp=0,lin=0;
	char c;
	while ((c=getc(file))!=EOF)
	{
		tot++;
		if (c=='\n')
			lin++;
		else
			if (c!='\n'||c!=' '||c!='\t')
				imp++;
	}
	printf("Total: %d\nImprimiveis: %d\nLinhas: %d\n",tot,imp,lin);
	fclose(file);
}
