#include <stdio.h>
main()
{
	char c;
	int i,j;
	float digit[10],carac=0,outros=0;
	for (i=0;i<=9;i++)
		digit[i]=0.0;
	while ((c=getchar())!=EOF)
	{
		if (c >= '0' && c <= '9')
			++digit[c-'0'];
		else
			outros++;
		carac++;
	}
	for (j=0;j<=9;j++)
		printf("%d - %f por cento\n",j,100*digit[j]/carac);
	printf("Outros caracteres - %f por cento\n",100*outros/carac);
}

