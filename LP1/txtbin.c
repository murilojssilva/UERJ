#include <stdio.h>
#include <string.h>
int main()
{
	FILE *txt,*bin;
	char c;
	txt=fopen("Ahorita.txt","r");
	bin=fopen("Ahorita.bin","w");
	while (c=getc(txt)!=EOF)
	{
		fprintf(bin,"%c",c);
	}
	fclose(bin);
	fclose(txt);
}
