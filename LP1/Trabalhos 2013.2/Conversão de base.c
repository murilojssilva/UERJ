#include<stdio.h>
#include<string.h>
void octtobin (char octal[], char binary[])
{
	int i, iBin = 0;
	for (i = 0; i < strlen(octal); i++)
	{
		switch(octal[i])
		{
			case '0':
				binary[iBin++] = '0';
				binary[iBin++] = '0';
				binary[iBin++] = '0';
				break;
			case '1':
				binary[iBin++] = '0';
				binary[iBin++] = '0';
				binary[iBin++] = '1';
				break;
			case '2':
				binary[iBin++] = '0';
				binary[iBin++] = '1';
				binary[iBin++] = '0';
				break;
			case '3':
				binary[iBin++] = '0';
				binary[iBin++] = '1';
				binary[iBin++] = '1';
				break;
			case '4':
				binary[iBin++] = '1';
				binary[iBin++] = '0';
				binary[iBin++] = '0';
				break;
			case '5':
				binary[iBin++] = '1';
				binary[iBin++] = '0';
				binary[iBin++] = '1';
				break;
			case '6':
				binary[iBin++] = '1';
				binary[iBin++] = '1';
				binary[iBin++] = '0';
				break;
			case '7':
				binary[iBin++] = '1';
				binary[iBin++] = '1';
				binary[iBin++] = '1';
				break;
		}
	}
	binary[iBin] = '\0';
}
void bintohexa(char binary[], char hexa[])
{
	char bin[5];
	int iBin, iHexa = 0, n, fim = 4, index, inicio = 0;
	while (fim <= strlen(binary))
	{
		n = 0;
		index = 0;
		for(iBin = inicio; iBin < fim; iBin++)
		{
			bin[index++] = binary[iBin];
		}
		if(bin[0] == '1')
			n += 8;
		if(bin[1] == '1')
			n += 4;
		if(bin[2] == '1')
			n += 2;
		if(bin[3] == '1')
			n += 1;
		if(n<10)
			hexa[iHexa++] = '0' + n;
		else
			switch(n)
			{
				case 10:
					hexa[iHexa++] = 'A';
					break;
				case 11:
					hexa[iHexa++] = 'B';
					break;
				case 12:
					hexa[iHexa++] = 'C';
					break;
				case 13:
					hexa[iHexa++] = 'D';
					break;
				case 14:
					hexa[iHexa++] = 'E';
					break;
				case 15:
					hexa[iHexa++] = 'F';
					break;
			}
		inicio = fim;
		fim +=4;
	}
	hexa[iHexa] = '\0';
}	
main()
{
	char numOct[50], numBin[200], numHex[50];
	gets(numOct);
	octtobin(numOct,numBin);
	bintohexa(numBin,numHex);
	printf("%s\n%s\n",numBin,numHex);
}
