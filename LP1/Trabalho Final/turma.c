#include <stdio.h>
#include <stdlib.h>
#include "turma.h"
#include "aluno.h"
#include "professor.h"
#define NAO 0
#define SIM 1
int novaMatricula,matriculaAluno;
char novaTurma[100];
struct turma *criaTurma(char nome[],int professor,int vagas,struct professor *p)
{
	struct turma *t = (struct turma *) malloc(sizeof(struct turma *));
	printf("Digite o nome da turma: ");
	scanf("%s\n",&nome);
	t->nome=nome;
	printf("Digite a matrícula do professor: ");
	do
	{
		printf("Matrícula inválida, digite-a novamente");
		scanf("%d: ",&professor);
		t->professor=professor;
		buscarProfessor(*p->nome,*p->matricula,**p);
		novaMatricula=*p->matricula;
	}while (novaMatricula != t->professor||t->professor!=0);
	printf("Digite a quantidade de vagas na turma");
	scanf("%d",&vagas);
	t->vagas=vagas;
	return t;
}
void insereTurma(char nome[],int professor, int vagas,struct turma ** t,struct professor *p)
{
	struct turma *elem = criaTurma(nome,professor,vagas,p);
	elem->listaInscritos= *t;
	*t=elem;
}
void libere(struct turma *del)
{
	free(del);
}

void excluiTurma(char nome[], int matricula,int vagas,int qtdInscritos, struct turma ** t,struct professor *p)
{
	int quest=NAO;
	char resp;
	if (*t)
	{
		if ((matricula==(*t)->matricula))
		{
			printf("%hs %hs %hd %hd %hd\n",&t->nome,&p->nome,&t->matricula,&t->vagas,&t->qtdInscritos);
			printf("Deseja excluir o elemento? (S - SIM\tN - NAO)");
			getch(resp);
			if (resp=='S')
				quest=SIM;
			else if (resp=='N')
				quest=NAO;
			else
			{
				printf("Erro ao excluir o elemento. Deseja exclui-lo? (S - SIM\tN - NAO)");
				getch(resp);
			}
			if (resp==SIM)
			{
				struct turma* del = *p;
				*t = del->listaInscritos;
				libere(del);	
			}
		}
		else
			excluiElementoCoord(nome,matricula, &((*p)->listaInscritos));
	}
	else
		printf("Elemento não encontrado!\n");
}
struct turma *alteraTurma(char nome[],int matricula,int vagas,int qtdInscritos,int professor, struct turma * t,struct professor *p)
{
	if (novaTurma==NULL)
		scanf("%s",&novaTurma);
	if (t)
	{
		if ((novaTurma==t->nome))
		{
			t->matricula=novaTurma;
			printf("Digite o nome da turma: ");
			scanf("%s\n",&nome);
			t->nome=nome;
			printf("Digite o número da matricula do professor: ");
			scanf("%d\n",&matricula);
			t->matricula=matricula;
			printf("Digite o nome do professor: ");
			scanf("%s\n",&nome);
			p->nome=nome;
			printf("Digite a quantidade de vagas: ");
			scanf("%d\n",&vagas);
			t->vagas=vagas;
			printf("Digite a quantidade de inscritos: ");
			scanf("%d\n",&qtdInscritos);
			t->qtdInscritos=qtdInscritos;
			return NULL;
		}	
		else
			return alteraTurma(nome,matricula,vagas,qtdInscritos,professor,t->listaInscritos ,p);
	}
	else
	{
		char novaTurma[] = NULL;
	}
}
struct turma *buscarTurma(char nome[], int matricula, struct professor * p,struct turma *t)
{
	if (novaMatricula!=0)
		scanf("%d",&novaMatricula);
	if (t)
		if ((novaMatricula == p->matricula))
		{
			printf("%hs",&p->nome);
			return *t;
		}
		else
			return buscaTurma(nome, matricula,p,t->listaInscritos);
	else
		{
			novaMatricula = 1;
			return NULL;
		}
}
void inserirAlunoTurma(char nome[],int matricula, struct turma *t,struct aluno *a)
{
	if (matriculaAluno!=0)
		scanf("%d",&matriculaAluno);
	if (t)
	{
		if ((matriculaAluno == a->matricula))
		{
			struct aluno *elem = criarAluno(nome,matricula);
			elem->listaInscritos= *a;
			*a=elem;
		}
	}
	else
		matriculaAluno = 1;
}
void buscarAlunoTurma(int matricula, struct turma *t, struct aluno **a)
{
	if (matriculaAluno!=0)
		scanf("%d",&matriculaAluno);
	if (t)
	{
		if ((matriculaAluno == a->matricula))
		{
			*a;
		}
		else
			buscarAlunoTurma(matricula,t,a);
	}
	else
	{
		novaMatricula = 1;
		//return NULL;
	}
}
struct turma *listarTurmas(struct turma *t)
{
	if (t)
		return t;
	else
		return NULL;
}
