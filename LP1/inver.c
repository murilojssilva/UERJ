#include<stdio.h>
int i=0,n;
void inverter(int );
int main()
{
	scanf("%d",&n);
	printf("%d\n",inverter(n));
}
void inverter(int n)
{
	inverter(getc(n));
	putchar(n); 
}
