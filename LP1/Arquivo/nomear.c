#include<stdio.h>
main()
{
	FILE *file;
	FILE *fp;
	char prog[10000],texto[100000000];
	fscanf(stdin,"%s",prog);
	file = fopen(prog,"w");
	char c;
	int carac=0,linha=0 ,imp=0;
	fscanf(stdin,"%s",texto);
	fprintf(stdout,"%s",texto);
	fclose(fp);
	fp=fopen(prog,"r");
	carac++;
	while ((c=getchar())!=EOF)
	{
		if (c!=' '||c!='\t'||c!='\n')
			imp++;
		else
			if (c=='\n')
				linha++;
	}
	printf("\nQtd de caracteres: %d\nQtd de linhas: %d\nQtd de caracteres imprimives: %d\n",carac, linha,imp);
	fclose(file);
}
