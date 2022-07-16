#include <stdio.h>
main()
{
	FILE *file;
	file=fopen("dados.txt","r");
	int i;
	for (i=1;i<=100;i++)
		printf("%d\n",i);
	fclose(file);
}
