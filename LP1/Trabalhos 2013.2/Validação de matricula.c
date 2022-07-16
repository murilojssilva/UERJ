#include<stdio.h>
#include<string.h>
#define VALIDA 1
#define INVALIDA 0
main()
{
	int i, cont = 0, valida, ano = 0, num, j, aux;
	char matricula[20];
	gets(matricula);
	valida = VALIDA;
	if(strlen (matricula) != 12)
		valida = INVALIDA;
	else
	{
		for(i = 0; i < 4; i++)
		{
			aux = matricula[i] - '0';
			for(j = 4-i; j > 1; j--)
			{
				aux*=10;
			}
			ano += aux;
		}
		if((ano < 1950) || (ano > 2013))
			valida = INVALIDA;
		else
		{
			if((matricula[4] != '1') && (matricula[4] != '2'))
				valida = INVALIDA;
			else
			{
				num = matricula[10] - '0';
				num *= 10;
				num += matricula[11] - '0';
				switch(num)
				{
					case 11: 
					case 12: 
					case 13:
					case 14:
					case 15:
					case 18:
					case 50:
					case 41:
						break;
					default:
						valida = INVALIDA;
						break;
				}
			}
		}
	}
	if(valida == VALIDA)
		printf("VALIDA");
	else
		printf("INVALIDA");
}
