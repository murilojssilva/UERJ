#include <stdio.h>
main()
{
	int i,num[5];
	char c,v[5];
	v[0]='a';
	v[1]='e';
	v[2]='i';
	v[3]='o';
	v[4]='u';
	printf("\nVogais: \n",v);
	for (i=0;i<5;i++)
	{
		num[i]=0;
	}
	while ((c=getchar())!=EOF)
	{
		if (c=='a')
			num[0]++;
		if (c=='e')
			num[1]++;
		if (c=='i')
			num[2]++;
		if (c=='o')
			num[3]++;
		if (c=='u')
			num[4]++;
	}
	printf("Qtd: \n",num);
}
