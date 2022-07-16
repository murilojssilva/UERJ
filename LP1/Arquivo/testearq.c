#include<stdio.h>
int main (void)
{
	FILE *file;
	file = fopen("teste.txt","w");
	fprintf(file,"Pão com mortadela");
	fclose(file);
}
