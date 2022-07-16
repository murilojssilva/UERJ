#include <stdio.h>
#include <string.h>
int main()
{
	FILE *txt,*bin;
	char c;
	//txt=fopen("Ahorita.txt","r");
	bin=fopen("Ahorita.bin","r");
	while (c=getc(bin)!=EOF)
	{
		printf("%c",c);
	}
	fclose(bin);
	//fclose(txt);
}
