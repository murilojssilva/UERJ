#include <stdio.h>
#include <string.h>
int main()
{
	char bin[32],pf[30];
	int i=0,j=0,v2=1,e='0';
	gets(bin);
	if (bin[i]=='0')
		pf[j]='+';
	else
		pf[j]='-';
	pf[1]='1';
	pf[2]=',';
	for (i=1;i<9;i++)
	{
		v2*=2;		
		if (i==1)
			pf[1]='1';
		else if (i==2)
			pf[2]=',';
		if (bin[i]=='1')
			e+=v2;
	}
	//e=e-'127';
	for (j=3;j<26;j++)
	{
		pf[j]=bin[j+6];
	}
	pf[j]='*';
	pf[++j]='2';
	pf[++j]='^';
	pf[++j]=e-127;
	printf("%s",pf);
}
