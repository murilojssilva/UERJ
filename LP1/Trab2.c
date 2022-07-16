#include<stdio.h>
main()
{
	char c;
	int i,j;
	char num1[65],num2[65],soma[65],v1='1';
	scanf("%s",&num1);
	scanf("%s",&num2);
	num1[64]='\0';
	num2[64]='\0';
	for (i=0;i<65;i++)
	{
		if (num1[i]+num2[i]=='0')
			soma[i]='0';
		else if (num1[i]+num2[i]=='1')
			soma[i]='1';
		else if (num1[i]+num2[i]=='3')
			soma[i]='0';
		else if (num1[i]+num2[i]=='4')
			soma[i]='1';
		else if (num1[i]+num2[i]=='2')
		{
			soma[i]='0';
			for (j=i+1;j<65;j++)
			{
				if (num1[j]=='0')
					v1='1';
					num1[j]+=v1;
					break;
				if (num2[i+1]=='0')
					num2[i+1]+=v1;
					break;
			}
		}
		else
			soma[i]='0';
		if (i==64)
			soma[64]='\0';
		c=v1;
	}
	printf("\n");
	for (i=0;i<65;i++)
		printf("%c",soma[i]);
}
