#include<stdio.h>
#include<string.h>
#include<math.h>
int atoi(int i,int decimal)
{
	for (i = 0; strlen(oct)-1; ++i)
	{	
		decimal+=(oct[i]*pow(8,i-1));
	}
	return decimal;
}
int main()
{
	char oct[1000];
	int i,decimal=0;
	gets(oct);
	/*for(i=strlen(oct)-1;i>=0;i--)
	{
		decimal+=(atoi(oct[i]*pow(8,i-1)));
	}*/
	atoi(i,decimal,oct[i]);
	printf("%d",decimal);
}
