#include <stdio.h>
main()
{
	FILE *file;
	file=fopen("dados.bin","w");
	int i;
	for (i=1;i<=100;i++)
		fprintf(file,"%d\n",i);
	fclose(file);
}
