#include <stdio.h>
#include <string.h>
void main ()
{
	char str1[10000],str2[10000],aux=' ';
	int i,j;
	gets(str1);
	for (i=strlen(str1)-1;i>=0;i--)
	{
		str2[j++]=str1[i];
	}
	printf ("%s\t%s",str1,str2);
	if (strcmp(str1,str2)==0)
		printf("\nÉ palíndromo\n");
	else
		printf("\nNao e palindromo\n");
	gets(str1);
}
