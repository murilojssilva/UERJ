#include <stdio.h>
#define IN 1
#define OUT 0
main()
{
	char c,d;//Comentário
	int state=OUT;
	while ((c=getchar())!=EOF)
	{
		if (c=='/')
			if (d=='/'||d=='*')
				while (d=getchar())!='\n')
					d=' ';
	}
}

