#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliar.h"
#include "professor.h"
#include "turma.h"
#include "aluno.h"
#define TAM 100
int novaMatricula=1;
struct aluno *criarAluno(char nome[],int matricula)
{
	struct aluno *a = malloc(sizeof(struct aluno *));
	gets(nome);
	scanf("%d",&matricula);
	a->nome = nome;
	a->matricula = matricula;
	return a;
}
void inserirAluno(char nome[],int matricula, struct aluno ** a)
{
	struct aluno *elen = criarAluno(nome,matricula);
	elen->listaInscritos= *a;
	*a=elen;
}
void libera(struct aluno * aux)
{
	free(aux);
}
void excluiAluno(char nome[], int matricula, struct aluno ** a)
{
	if (*a)
	{
		if ((matricula==(*a)->matricula))
		{
			struct aluno* aux = *a;
			*a = aux->listaInscritos;
			libera(aux);
		}
		else
			excluiElementoCoord(nome,matricula, &((*a)->next));
	}
	else
		printf("Elemento n?o encontrado!\n");
}
struct aluno *alteraAluno(char nome[], int matricula, struct aluno * a)
{
	if (novaMatricula!=0)
		scanf("%d",&novaMatricula);
	if (a)
	{
		if ((novaMatricula==a->matricula))
		{
			a->matricula = novaMatricula;
			printf("Digite o nome do aluno: ");
			scanf("%s\n",&nome);
			a->nome=nome;
			return NULL;
		}	
		else
			return alteraProfessor(nome, matricula, a->listaInscritos);
	}
	else
	{
		novaMatricula = 0;
		return NULL;
	}
}
struct aluno *buscaAluno(char nome[], int matricula, struct aluno *a)
{
	if (novaMatricula!=0)
		scanf("%d",&novaMatricula);
	if (a)
		if ((novaMatricula==a->matricula))
			return *a;
		else
			return buscaProfessor(nome, matricula, a->listaInscritos);
	else
		{
			novaMatricula = 0;
			return NULL;
		}
}
struct aluno *listarAluno(struct aluno *a)
{
	if (a)
		return *a;
	else
		return NULL;
}
