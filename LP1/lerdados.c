#include<stdio.h>
FILE *file;
char c;
int tot=0,H,M,FS,FN;
typedef struct
{
	char sexo[2],fum[2];
	int idade;
}dados;
void lerDados();
void main()
{
	int n;
	file=fopen("resposta.bin")
	fscanf(file,"Quantidade de f%d",n);
	lerDados();
	analisarDados();
}
void lerDados()
{
	int i;
	for (i=0;i<n;i++)
	{
		tot++;;
		fgets(dados.sexo[i],2,file);
		fgetc(file);
		fgets(dados.fum[i],2,file);
		fgetc(file);
		fscanf(file,"%d",dados.idade[i]);
		fgetc(file);
	}
}
void analisaDados()
{
	for (i=0;i<n;i++)
	{
		if (dados.sexo[i]=='M')
			M++;
		else if (dados.sexo[i]=='F')
			F++;
		if (dados.fum[i]=='S')
			FS++
		else if (dados.fum[i]=='N')
			FN++;
	}
}
	
