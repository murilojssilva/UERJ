#include <stdio.h>
int main()
{
	int esp=0, tab=0, enter=0;
	char c;
	while ((c=getchar())!=EOF)
		switch (c)
		{
			case ' ':
				esp++;
				break;
			case '\t':
				tab++;
				break;
			case '\n':
				enter++;
				break;
		}
	printf("\n%d %d %d\n", esp, tab, enter);
}
