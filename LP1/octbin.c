#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	char num[10000];
	int i,n=0;
	gets(num);
	for (i=strlen(num)-1;i<=0;i--)
		n+=atoi(num[i]*pow(8,i));
	printf("%d",n);
}
