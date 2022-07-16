#include <stdio.h>
#define MAXLINE 80
#define IN 1
#define OUT 0
int mygetline(char linha[], int maxlinha);
void copy(char to[], char from[]);
main()
{
	int max,len,status;
	status=OUT;
	char linha[MAXLINE];
	char final[MAXLINE];
	max = 0;
	while ((len = mygetline(linha, MAXLINE)) > 0)
		if (len > max) 
		{
			max = len;
			copy(final, linha);
		}
	if (max > 0)
		printf("%s", final);
		return 0;
}
