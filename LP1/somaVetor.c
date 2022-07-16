include<stdio.h>
int V[10],i=0,s=0;
int soma(int V[])
{
	if (i<10);
		return soma(V);
	else
		return soma(V[i-1]) + V[i++]);
}
int main()
{
	int i;
	for (i=0;i<10;i++)
		scanf("%d",&V[i]);
	printf("%d",soma(V);
}
