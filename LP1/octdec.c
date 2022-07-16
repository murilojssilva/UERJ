/*Modifique a função atoi(char []) para que esta faça a conversão
de uma string contendo um número octal (base 8) para o valor
correspondente na base decimal.
*/
#include<stdio.h>
#include<string.h>
int decimal(int i,char oct[i],int x8);
int main()
{
	char oct[1000],dec[10000],x8;
	int i;
	gets(oct);
	conv(i,oct[i],x8);
	//decimal=atoi(dec);
	printf("%s",dec);
}
int conv(int i,char oct[i],char x8,char dec[10000])
{
	x8='1';	
	for (i=0;i<strlen(oct);i++)
	{
		dec+=(oct[i]*x8);
		x8*='8';
	}
	return 0;
}
