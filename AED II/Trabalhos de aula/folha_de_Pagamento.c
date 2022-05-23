

int main()
{
	funcionario funcionarios[10];
	horasTrabalhadas cargaHoraria[10];
	AdicionarFuncionarios(funcionarios);
	QtdHorasTrab(cargaHoraria);
	CalculoSalario(funcionarios,cargaHoraria);
	//ordenarMergeSortFolhaPagamento(0,9);
	FolhaDePagamento();
}

void AdicionarFuncionarios(funcionario funcionarios[])
{
	int i = 0;
	FILE* file;
	file=fopen("Funcionarios.txt","r");
	for (i=0;i<10;i++)
	{
		fgets(funcionarios[i].nome,51,file);
		//fgetc(file);
		fgets(funcionarios[i].matricula,13,file);
		//fgetc(file);
		fgets(funcionarios[i].endereco,66,file);
		//fgetc(file);
		fgets(funcionarios[i].CPF,12,file);
		//fgetc(file);
		fgets(funcionarios[i].cod_Banco,4,file);
		//fgetc(file);
		fgets(funcionarios[i].agencia,6,file);
		//fgetc(file);
		fgets(funcionarios[i].conta,9,file);
		//fgetc(file);
		fscanf(file," %f",&funcionarios[i].valorHora);
	}
	fclose(file);
}
void QtdHorasTrab(horasTrabalhadas cargaHoraria[])
{
		FILE* arquivo;
		arquivo=fopen("Novembro.txt","r");
		char linha[10000];
		int i=0;
		for (i=0;i<10;i++)
		{
		   //if(fgets(linha,10000,arquivo)!=NULL)
		   //{
				sscanf(linha,"%12s/%d",cargaHoraria[i].matricula,&cargaHoraria[i].horasTrabalhadas);
			//}
		}
		fclose(arquivo);
}
void CalculoSalario(funcionario funcionarios[],horasTrabalhadas cargaHoraria[])
{
	FILE *arq;
	arq = fopen("Funcionarios.txt","r");
	int j,i;
	for (i=0;i<10;i++)
	{
	   for (j=0;strcmp(funcionarios[i].matricula,cargaHoraria[i].matricula) !=0 ;j++);
		strcpy(FolhaPagamento[i].nome,funcionarios[i].nome);
		strcpy(FolhaPagamento[i].CPF,funcionarios[i].CPF);
		strcpy(FolhaPagamento[i].cod_Banco,funcionarios[i].cod_Banco);
		strcpy(FolhaPagamento[i].agencia,funcionarios[i].agencia);
		strcpy(FolhaPagamento[i].conta,funcionarios[i].conta);
		FolhaPagamento[i].salario = funcionarios[i].valorHora * cargaHoraria[i].horasTrabalhadas;
	}
	fclose(arq);
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
	horasTrabalhadas aux[final-inicio+1];
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
