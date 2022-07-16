#include<stdio.h>
int main()
{
	char c[20],op;
	int a,b;
	sscanf(c, "%i %l[+-*/] %i" ,&a,&op,&b);
	printf("%s",c);
}
