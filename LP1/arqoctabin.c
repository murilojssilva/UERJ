#include<stdio.h>
#include <string.h>
int main()
{
	FILE *file;
	file=fopen("decimal.txt","r");
	char octa[1000],bin[1000];
	int i,j=0;
	fscanf(file,"%s",octa);
	for (i=0;i<strlen(octa);i++)
	{
		switch(octa[i])
		{
			case '0':
				bin[j++]='0';
				bin[j++]='0';
				bin[j++]='0';
				break;
			case '1':
				bin[j++]='0';
				bin[j++]='0';
				bin[j++]='1';
				break;
			case '2':
				bin[j++]='0';
				bin[j++]='1';
				bin[j++]='0';
				break;
			case '3':
				bin[j++]='0';
				bin[j++]='1';
				bin[j++]='1';
				break;
			case'4':
				bin[j++]='1';
				bin[j++]='0';
				bin[j++]='0';
				break;
			case'5':
				bin[j++]='1';
				bin[j++]='0';
				bin[j++]='1';
				break;
			case'6':
				bin[j++]='1';
				bin[j++]='1';
				bin[j++]='0';
				break;
			case'7':
				bin[j++]='1';
				bin[j++]='1';
				bin[j++]='1';
				break;
		}
	}
	bin[j]='\0';
	puts(bin);
}
