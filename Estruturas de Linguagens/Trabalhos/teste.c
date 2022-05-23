#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define IN 1 // dentro das aspas
#define OUT 0 // fora das aspas
#define INA 2 
void main()
{
	char c,d,s[400],auxn[4],auxf[100],a[100];
	int n = 0,i=0,j=0,stai = OUT,staf = OUT, par = OUT,estpar = 0,estasp = 0,state = OUT,estnum = 0,k=0,estesp = OUT,soma = 0;
	float num = 0.0,somaf = 0.0;
	while  ((c=getchar())!=EOF)
	{

		if (c == '\n')
		{
			if (estpar == OUT)
			{
				for (;k<strlen(auxf)-1;k++)
					if (isalpha(auxf[k]))
						s[i++]  = auxf[k];
			}
			if (estnum == IN)
			{
				if (staf == IN)
				{
					//if (isdigit(c))
					//	auxf[j++] = c;
					//auxf[j] = '\0';
					//somaf += atof(auxf);
					//char auxf[100];
					sprintf(a, "%f", somaf);
					for (;k<3;k++)
						s[i++]  = a[k];
				}
				else if (staf == OUT)
				{
					soma += d;
					sprintf(a,"%d",soma);
					s[i++] = a[0];
				}
				estnum = OUT;
				char a[100];
			}
			else if (estnum == OUT)
			{
				i -= strlen(auxn)-1;
			}
			if (estasp == IN)
			{
				s[i++] = '"';
			}
			staf = OUT;
			j = 0;
			k = 0;
			soma = 0;
			somaf = 0.0;
			state = OUT;
			state = OUT;
			estpar = OUT;
			estasp = OUT;
			estnum = OUT;
		}
		if (c == '"')
		{
			if (state == OUT && estasp == OUT)
			{
				s[i++] = c;
				state = IN;
			}
			else if (state == IN)
			{
				state = INA;
			}
			estasp = IN;
		}
		/*else if (c == ' ')
		{
			if (state == OUT)
				estesp = IN;
		}
		else if (c != ' ')
		{
			if (state == OUT)
				estesp = OUT;
		}*/
		else if (d == '\n')
		{
			if (c != '"')
				estpar = IN;
		}
		else if (c == '(')
		{
			estpar = IN;
			if (par == OUT)
				par = IN;
			else if (par = IN)
				par = INA;
		}
		else if (isdigit(c) || c == '.')
		{
			if (d == '\n')
				par = IN;
			if (isdigit(c))
				estnum = IN;
			state == OUT;
			
		}
		else if (c == '.')
		{
			staf = IN;
			if (isdigit(d))
			{
				auxf[j++] = d;
				auxf[j++] = c;	
			}
			if (estasp == IN)
				state == OUT;
		}
		else if (c == ')')
		{
			if (par == INA)
				par == IN;
			else if (par ==IN)
				par == OUT;
			//}
			k = 0;
			n = 0;
			num = 0.0;
		}
		else if (c == '+')
		{
			if (estnum == IN)
			{
				puts(auxn);
				if (strlen(auxn) == 1)
					soma += atoi(auxn);
				else if (strlen(auxn) == 3)
					somaf += atof(auxn);
				if (strlen(auxn) == 2 || strlen(auxn)== 4)
					for (k=0;k < strlen(auxn);k++)
						s[i++] = auxn[k];
					i--;
				char auxn[100];
			}
			k = 0;
			if (isdigit(d))
				n += d - '0';
		}
		else if (isalpha(c) ||state == INA || state == IN || estesp == OUT)  
			s[i++] = c;
		d = c;
	}
	s[i] = '\0';
	puts(s);
}
