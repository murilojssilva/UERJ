#include <stdio.h>
#include <stdlib.h>
main()
{
	int vogais,i;
	char frase;
	scanf("Digite uma frase: %s",&frase);
	while (i < strlen(frase)+1)
	{
		if (frase[i]="a"||frase[i]="e"||frase[i]="i"||frase[i]="o"||frase[i]="u")
			vogais++;
		i++;
	}
}
