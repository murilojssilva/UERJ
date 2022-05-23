#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define IN 1 // dentro das aspas
#define OUT 0 // fora das aspas
#define INA 2 // nas aspas
#define NUM 3
void main()
{
	char c,d='\0',aux[10];
	char *s = (char*) malloc(sizeof(char));
	//char *num = (char*) malloc(sizeof(char));
	int state=OUT,par=OUT,i=0,temn=OUT,n,soma = 0, str = 0, x = 1,j=0;
	while ((c=getchar())!=EOF)
	{
		if (c =='\n' && state == INA)
		{
			if (temn == OUT)
			{
				temn = OUT;
				sprintf(aux, "%d", soma);
				for (j = 0; j<strlen(aux);j++)
					s[i++] = aux[j];
				soma = 0;
			}
			s[i++] = c;
			state = OUT;
		}
		else if (c !='"' && state == OUT)
			state = INA;
		else if (c == '"' && state == OUT)
		{
			str = 1;
			state == INA;
		}
		else if (c =='"' && state == INA)
		{
			s[i++] = c;
			state = IN;
		}
		else if (c !='"' && state == IN)
			state = INA;
		else if (c == '(' && par == OUT)
			par = IN;
		else if (c == '(' && par == IN)
			par =  INA;
		else if (c == ')' && par == INA)
			par = IN;
		else if (c == ')' && par == IN)
			par = OUT;
		else if (isdigit(c) && par == INA || par == IN)
		{
			temn = IN;
			n = c - '0';
			soma += n;
			n = 0;
		}
		else if (isdigit(c) && state == OUT)
		{
			temn = IN;
			s[i++] = c;
		}
		else if (c == '+' && par == INA || par == IN) 
		{
			soma += n;
			n = 0;
		}
		//if (state == INA || state == IN || par == INA)
		//	s[i++] = c;
		if (state == INA)
			s[i++] = c;
		d = c;
	}
	puts(s);
}
