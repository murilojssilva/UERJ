#include <stdio.h>
#include <stdlib.h>
char n[100],octal[200],i=0,j=0;
void conversao(char n[]);
int main()
{
	gets(n);
	conversao(n);
	printf("%s",octal);
}
void conversao(char n[])
{
	for (i=0;i<(strlen(n);i++);
		octal[n-i]=n[j++]%'8';
	octal[n-i]=n[j++]%'8';
}
