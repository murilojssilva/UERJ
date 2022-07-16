#include <stdio.h>
main()
{
	char c;
	int i,j,carac=0;
	int digit[10];
	for (i=0;i<=9;i++)
		digit[i]=0;
	while ((c=getchar())!=EOF)
	{
		if (c >= '0' && c <= '9')
			++digit[c-'0'];
		else
			carac++;
	}
	for (j=0;j<=9;j++)
		printf("%d - %d\n",j,digit[j]);
	printf("Outros caracteres - %d\n",carac);
}
