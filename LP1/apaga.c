#include <stdio.h>
#define IN 1/*afuaudfnvadividaaidfafinafinaidfn*/
#define OUT 0
main()
{
	char c=' ',d;
	int status=OUT;
	while ((d=getchar())!=EOF)
	{
		if (c=='/' && d=='*')
			status=IN;
		if (status==IN)
		{
			if (c=='*' && d=='/'||d=='/')
			{
				status=OUT;
			}
			else if (d=='*'||d=='/')
				d='\b';
			else
				d='\b';
		}
		putchar(d);		
		c=d;
	}
}
