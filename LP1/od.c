#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char num[100],octal[200],j;
void conversao(char num[]);
int main()
{
	gets(num);
	j=0;
	conversao(num);
	puts(octal);
}
void conversao(char n[])
{
	int i;
	for (i=0;i<=(strlen(num));i++)
	{
		octal[j++]=n[i]%'8';
	}
	octal[j++]=n[i]%'8';
}
