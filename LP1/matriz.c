#include <stdio.h>
main()
{
	int n,i,j,a,b;
	scanf("Valor de n: %d\n",&n);
	int matriz [n][n];
	for (i=0;i<=n;i++)
	{
		for (j=0;j<=n;j++)
		{
			scanf("%d ",&matriz[i][j]);
			if (matriz[i][j]!=0||matriz[i][j]!=1)
				scanf("%d ",&matriz[i][j]);
			printf("\n");
		}
	}
	for (i=0;i<=n;i++)
	{
		for (j=0;j<=n;j++)
		{
			if (matriz[i][j]==1 && matriz[i+j][i+j]==1)
			{
				a=i;
				b=j;
			}
		}
	}
	for (i=0;i<=a;i++)
		for (j=0;j<=b;j++)
			printf("%d ",matriz[a][b]);
	printf("Posição %d%d",a,b);
}
