#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct funcionario
{
	char nome[51], matricula[13], endereco[66], cpf[12], codBanco[4], agencia[6], conta[9];
	float valorHora;
};
struct cargaHoraria
{
	char matricula[13];
	int qtdeHorasTrabalhadas;
};
struct salario
{
	char nome[51], cpf[12], codBanco[4], agencia[6], conta[9];
	float salario;
};

typedef struct funcionario funcionario;
typedef struct cargaHoraria cargaHoraria;
typedef struct salario salario;
salario folhaPagamento[10];
	
void lerFuncionarios(funcionario[]);
void lerHorasTrabalhadas(cargaHoraria[]);
void calcularSalarios(funcionario[],cargaHoraria[]);
void ordenarMergeSortFolhaPagamento(int, int);
void merge(int,int,int);
salario preencher(salario);
void criarFolhaPagamento();


int main()
{
	funcionario funcionarios[10];
	cargaHoraria horasTrabalhadas[10];
	lerFuncionarios(funcionarios);
	lerHorasTrabalhadas(horasTrabalhadas);
	calcularSalarios(funcionarios,horasTrabalhadas);
	ordenarMergeSortFolhaPagamento(0,9);
	criarFolhaPagamento();
	return 0;
}

void lerFuncionarios(funcionario funcionarios[])
{
	int i = 0;
	FILE* arquivo;
	if((arquivo = fopen("Funcionarios.txt","r"))==NULL)
	{
		fprintf(stderr,"O arquivo Funcionarios.txt nao foi encontrado");
		exit(1);
	}
	else
	{
		for(i=0;i<10;i++)
		{
			fgets(funcionarios[i].nome,51,arquivo);
			fgetc(arquivo);
			fgets(funcionarios[i].matricula,13,arquivo);
			fgetc(arquivo);
			fgets(funcionarios[i].endereco,66,arquivo);
			fgetc(arquivo);
			fgets(funcionarios[i].cpf,12,arquivo);
			fgetc(arquivo);
			fgets(funcionarios[i].codBanco,4,arquivo);
			fgetc(arquivo);
			fgets(funcionarios[i].agencia,6,arquivo);
			fgetc(arquivo);
			fgets(funcionarios[i].conta,9,arquivo);
			fscanf(arquivo," %f ",&funcionarios[i].valorHora);
		if(ferror(arquivo))
		{
		    fprintf(stderr,"Ocorreu um erro na leitura do arquivo funcionario.txt");
		    exit(2);
		}
	}
		fclose(arquivo);
		if(ferror(arquivo))
		{
			fprintf(stderr,"Erro ao fechar o arquivo funcionarios.txt");
			exit(3);
		}
	}
}

void lerHorasTrabalhadas(cargaHoraria horasTrabalhadas[])
{
	char linha[10000];
	int i = 0;
	FILE* arquivo;
	if((arquivo = fopen("Novembro.txt","r"))==NULL)
	{
		fprintf(stderr,"O arquivo Novembro.txt não foi encontrado");
		exit(1);
	}
	else
	{
		for(i=0;i<10;i++)
		{
		    if(fgets(linha,10000,arquivo)!=NULL)
		    {
		        sscanf(linha,"%12s/%d",horasTrabalhadas[i].matricula,&horasTrabalhadas[i].qtdeHorasTrabalhadas);
		    }
		    if(ferror(arquivo))
		    {
		        fprintf(stderr,"Ocorreu um erro na leitura do arquivo Novembro.txt");
		        exit(2);
		    }
		}
		fclose(arquivo);
		if(ferror(arquivo))
		{
			fprintf(stderr,"Erro ao fechar o arquivo Novembro.txt");
			exit(3);
		}
	}
}

void calcularSalarios(funcionario funcionarios[],cargaHoraria horasTrabalhadas[])
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0; strcmp(funcionarios[i].matricula,horasTrabalhadas[j].matricula) != 0; j++)
			;
		strcpy(folhaPagamento[i].nome,funcionarios[i].nome);
		strcpy(folhaPagamento[i].cpf,funcionarios[i].cpf);
		strcpy(folhaPagamento[i].codBanco,funcionarios[i].codBanco);
		strcpy(folhaPagamento[i].agencia,funcionarios[i].agencia);
		strcpy(folhaPagamento[i].conta,funcionarios[i].conta);
		folhaPagamento[i].salario = funcionarios[i].valorHora * horasTrabalhadas[j].qtdeHorasTrabalhadas;
	}
}


void ordenarMergeSortFolhaPagamento(int inicial, int final)
{
	int i;
	if(final > inicial)
	{
		i = floor((final + inicial)/2);
		ordenarMergeSortFolhaPagamento(inicial,i);
		ordenarMergeSortFolhaPagamento(i+1,final);
		merge(inicial,i,final);
	}
}

void merge(int inicio, int div, int final)
{
	salario aux[final-inicio+1];
	int i = inicio,j = div+1,k = 0;
	while((i <= div)&&(j <= final))
	{
		if(strcmp(folhaPagamento[i].nome,folhaPagamento[j].nome) > 0)
		{
			aux[k] = preencher(folhaPagamento[j]);
			j++;
		}
		else
		{
			aux[k] = preencher(folhaPagamento[i]);
			i++;
		}
		k++;
	}
	while(i <= div)
	{
		aux[k] = preencher(folhaPagamento[i]);
		i++;
		k++;
	}
	while(j <= final)
	{
		aux[k] = preencher(folhaPagamento[j]);
		j++;
		k++;
	}
	for(i = inicio, j = 0; i <= final && j < (final-inicio+1); i++, j++)
	{
		folhaPagamento[i] = preencher(aux[j]);
	}
}

salario preencher(salario salarioFunc)
{
	salario aux;
	strcpy(aux.nome,salarioFunc.nome);
	strcpy(aux.cpf,salarioFunc.cpf);
	strcpy(aux.codBanco,salarioFunc.codBanco);
	strcpy(aux.agencia,salarioFunc.agencia);
	strcpy(aux.conta,salarioFunc.conta);
	aux.salario = salarioFunc.salario;
	return aux;
}

void criarFolhaPagamento()
{
    int i;
    for(i=0;i<10;i++)
    {
    	printf("%s|%s|%s|%s|%s|%.2f\n",folhaPagamento[i].nome,folhaPagamento[i].cpf,folhaPagamento[i].codBanco,folhaPagamento[i].agencia,folhaPagamento[i].conta,folhaPagamento[i].salario);
    }
}