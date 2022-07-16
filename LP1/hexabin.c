#include <stdio.h>
#include <string.h>
main()
{
	char oct[10000],dec[10000];
	int i,x8=1,decimal;
	puts(oct);
	for (i=strlen(oct)-1;i>=0;i++)
	{
		dec+=(x8*oct[i]);
		x8*=8;
	}
	decimal=atoi(dec);
	printf("%d",decimal);
}
