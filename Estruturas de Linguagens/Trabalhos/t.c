#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define IN 1 // dentro das aspas
#define OUT 0 // fora das aspas
#define INA 2 
void main()
{
	char c,d,s[400],aux[100],auxf[100],a[100];
	int n = 0,i=0,j=0,stai = OUT,staf = OUT, par = OUT,estpar = 0,estasp = 0,state = OUT,estnum = 0,k=0,estesp = IN, estpon = OUT,soma = 0;
	float num = 0.0,somaf = 0.0;
	while  ((c=getchar())!=EOF)
	{
		/*if (c == '.' && (par == IN || par == INA) && estasp == IN)
		{
			staf = IN;
			if (isdigit(d))
				auxf[j++] = d;
			auxf[j++] = c;
		}*/
		/*
		else if (isdigit(c) && par == IN)
		{
			state = OUT;
			estnum = IN;
			if (staf == OUT)
			{	
				n = c - '0';
				soma += n;
				n = 0;
			}
			else if (staf == IN)
			{
				auxf[j++] = c;
				auxf[j++] = '0';
				auxf[j++] = '\0';
				num = atof(auxf);
				printf("%.2f",num);
				somaf += num;
				auxf[0]='\0';
				j=0;
				staf = OUT;
			}
		}*/
		if (c == ' ')
		{
			/*if (estpar == OUT)
			{
				for (;k<strlen(auxf)-1;k++)
				s[i++]  = auxf[k];
			}*/
			if (staf == IN)
			{
				sprintf(a, "%f", somaf);
				for (;k<3;k++)
					s[i++]  = a[k];
			}
			else if (staf == OUT)
			{
				sprintf(a,"%d",soma);
				if (estnum == IN)
					s[i++] = a[0];
			}
			char a[100];
		}
		else if (c == '\n')
		{
			if (estasp == IN)
			{
				s[i++] = '"';
			}
			//s[i++] = '\n';
			staf = OUT;
			j = 0;
			k = 0;
			soma = 0;
			somaf = 0.0;
			state = OUT;
			state = OUT;
			estpar = OUT;
			estpon = OUT;
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
		else if (isdigit(c))
		{
			if (d == '\n')
				par = IN;
			estnum == IN;
			state == OUT;
		}
		else if (isdigit(d))
		{
			if (c != '.')
			{
				n = c - '0';
			}
		}
		else if (c == '.')
		{
			estpon = IN;
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
			if (estnum == IN && staf == OUT)
				soma += n;
			else if (estnum == IN && staf == IN)
				somaf += n;
			if (par == OUT && estpar == IN)
			{
				if (staf == IN)
				{
					if (isdigit(c))
						auxf[j++] = c;
					auxf[j++] = '\0';
					num = atof(auxf);
					somaf += num;
					char auxf[100];
				}
				else if (staf == OUT)
					soma += n;
				n = 0;
				num = 0.0;	
			}
		}
		else if (isalpha(c) ||state == INA || state == IN ||estesp == IN)
			//if (c != '-' && state == IN || state == INA)
				s[i++] = c;
		d = c;
	}
	s[i] = '\0';
	puts(s);
}
