#include <stdio.h>
#define IN 1
#define OUT 0
#define INA 1
#define OUTA 0
void main()
{
	char c,d;
	int status=OUT,statusa=OUTA,i=0;
	while ((c=getchar())!=EOF)
	{
		if (c=='\n')
				{
					status=OUT;
					statusa=OUTA;
				}
		else if (d=='*'&&c=='/'||d=='/'&&c=='*')
		{
			statusa=IN;
		}
		else if (c=='/'||c=='*')
		{
				status=INA;
		}
		else if (d=='*'&& c=='/')
			{
				status=OUT;
				statusa=OUTA;
			}
		else
		{
		
			if (status==OUT && statusa==OUTA)
			{
				putchar(c);
			}
			else if (status=IN||statusa==INA)
			{
				if (d=='*'&& c=='/')
				{
					status=OUT;
					statusa=OUTA;
				}
			}
		}
		d=c;
	}
}
