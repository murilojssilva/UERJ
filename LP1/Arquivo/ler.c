#include <stdio.h>
main()
{
	FILE *file;
	file=fopen("Ahorita.txt","r");
	int i=1;
	char c;
	printf("%d ",i);
	while((c=getc(file))!=EOF)
	{
		if (c=='\n')
		{
			i++;
			printf("\n%d ",i);
		}
		else 
			printf("%c",c);
	}
	fclose(file);
}
