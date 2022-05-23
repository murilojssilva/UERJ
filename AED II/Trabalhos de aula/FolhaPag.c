#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
	char nome[51];
	char matricula[13];
	char endereco[66];
	char CPF[12];
	char cod_Banco[4];
	char agencia[6];
	char conta[9];
	float valorHora;
}funcionario;

typedef struct
{
	char matricula[13];
	int horasTrabalhadas;
}horasTrabalhadas;

typedef struct
{
	char nome[51];
	char CPF[12];
	char cod_Banco[4];
	char agencia[6];
	char conta[9];
	float salario;
}salario;

void AdicionarFuncionarios(funcionario[]);
void QtdHorasTrab(horasTrabalhadas[]);
void CalculoSalario(funcionario[],horasTrabalhadas[]);
void ordenarMergeSortFolhaPagamento(int, int);
void merge(int,int,int);
salario preencher(salario);
void FolhaDePagamento();

salario FolhaPagamento[10];
funcionario funcionarios[10];
horasTrabalhadas cargaHoraria[10];


int main()
{
	AdicionarFuncionarios(funcionarios);
	QtdHorasTrab(cargaHoraria);
	CalculoSalario(funcionarios,cargaHoraria);
	ordenarMergeSortFolhaPagamento(0,9);
	FolhaDePagamento();
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
			fgets(funcionarios[i].CPF,12,arquivo);
			fgetc(arquivo);
			fgets(funcionarios[i].cod_Banco,4,arquivo);
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

void lerHorasTrabalhadas(horasTrabalhadas cargaHoraria[])
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
		        sscanf(linha,"%12s/%d",cargaHoraria[i].matricula,&cargaHoraria[i].horasTrabalhadas);
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

void calcularSalarios(funcionario funcionarios[],horasTrabalhadas cargaHirarua[])
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0; strcmp(funcionarios[i].matricula,cargaHoraria[j].matricula) != 0; j++);
		strcpy(FolhaPagamento[i].nome,funcionarios[i].nome);
		strcpy(FolhaPagamento[i].CPF,funcionarios[i].CPF);
		strcpy(FolhaPagamento[i].cod_Banco,funcionarios[i].cod_Banco);
		strcpy(FolhaPagamento[i].agencia,funcionarios[i].agencia);
		strcpy(FolhaPagamento[i].conta,funcionarios[i].conta);
		FolhaPagamento[i].salario = funcionarios[i].valorHora * cargaHoraria[j].horasTrabalhadas;
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
		if(strcmp(FolhaPagamento[i].nome,FolhaPagamento[j].nome) > 0)
		{
			aux[k] = preencher(FolhaPagamento[j]);
			j++;
		}
		else
		{
			aux[k] = preencher(FolhaPagamento[i]);
			i++;
		}
		k++;
	}
	while(i <= div)
	{
		aux[k] = preencher(FolhaPagamento[i]);
		i++;
		k++;
	}
	while(j <= final)
	{
		aux[k] = preencher(FolhaPagamento[j]);
		j++;
		k++;
	}
	for(i = inicio, j = 0; i <= final && j < (final-inicio+1); i++, j++)
	{
		FolhaPagamento[i] = preencher(aux[j]);
	}
}

salario preencher(salario salarioFunc)
{
	salario aux;
	strcpy(aux.nome,salarioFunc.nome);
	strcpy(aux.CPF,salarioFunc.CPF);
	strcpy(aux.cod_Banco,salarioFunc.cod_Banco);
	strcpy(aux.agencia,salarioFunc.agencia);
	strcpy(aux.conta,salarioFunc.conta);
	aux.salario = salarioFunc.salario;
	return aux;
}

void FolhaDePagamento()
{
    int i;
    for(i=0;i<10;i++)
    {
    	printf("%s|%s|%s|%s|%s|%.2f\n",FolhaPagamento[i].nome,FolhaPagamento[i].CPF,FolhaPagamento[i].cod_Banco,FolhaPagamento[i].agencia,FolhaPagamento[i].conta,FolhaPagamento[i].salario);
    }
}
