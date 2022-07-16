#include <stdlib.h>
#include <stdio.h>
int main()
{
	char nomeArq1[100], nomeArq2[100], linhaArq1[1000],linhaArq2[1000];
	FILE *arquivo1, *arquivo2;
	int i, linha = 0;
	scanf("%s",nomeArq1);
	scanf("%s",nomeArq2);
	arquivo1 = fopen(nomeArq1,"r");
	if(arquivo1 == NULL)
	{
		fprintf(stderr,"Erro ao abrir o arquivo %s",nomeArq1);
		exit(1);
	}
	arquivo2 = fopen(nomeArq2,"r");
	if(arquivo2 == NULL)
	{
		fprintf(stderr,"Erro ao abrir o arquivo %s",nomeArq2);
		exit(1);
	}
	while((fgets(linhaArq1, 1000, arquivo1) != NULL) && (fgets(linhaArq2, 1000, arquivo2) != NULL))
	{
		linha += 1;
		for(i = 0; i < 1000 && linhaArq1[i] == linhaArq2[i] && linhaArq1[i] != '\n' && linhaArq2[i] != '\n'; i++)
			;
		if(linhaArq1[i] != linhaArq2[i])
		{
			printf("Discrepância: Linha %d, Coluna %d.\n",linha,++i);
			return 0;
		}
	}
	if(ferror(arquivo1))
	{
		fprintf(stderr,"Erro na leitura do arquivo %s",nomeArq1);
		exit(2);
	}
	if(ferror(arquivo2))
	{
		fprintf(stderr,"Erro na leitura do arquivo %s",nomeArq2);
		exit(2);
	}
	printf("Os arquivos %s e %s são idênticos.\n",nomeArq1,nomeArq2);
	return 0;
}
