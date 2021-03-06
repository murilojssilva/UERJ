#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliar.h"
#define TAM 100
int novaMatricula=1;
struct professor *criaProfessor(char nome[],int matricula)
{
	struct professor * p = (struct professor *)
		malloc(sizeof(TAM));
	printf("Digite o nome da turma: ");
	scanf("%s\n",&nome);
	p->nome=nome;
	printf("Digite a matr?cula do professor: ");
	scanf("%d: ",&matricula);
	p->matricula=matricula;
	return p;
}

void insereProfessor(char nome[],int matricula, struct professor ** p)
{
	struct professor *ele = criaProfessor(nome,matricula);
	ele->listaInscritos= *p;
	*p=ele;
}
void liberar(struct professor *exc)
{
	free(exc);
}
void excluiProfessor(char nome[], int matricula, struct professor ** p)
{
	if (*p)
	{
		if ((matricula==(*p)->matricula))
		{
			printf("%hs",p->nome);
			struct professor* exc = *p;
			*p = exc->listaInscritos;
			liberar(exc);
			criaProfessor(nome,matricula);
			insereProfessor(nome,matricula,p);
		}
		else
			excluiElementoCoord(nome,matricula, &((*p)->listaInscritos));
	}
	else
		printf("Elemento n?o encontrado!\n");
}
struct professor *alteraProfessor(char nome[], int matricula, struct professor * p)
{
	if (novaMatricula!=0)
		scanf("%d",&novaMatricula);
	if (p)
	{
		if ((novaMatricula==p->matricula))
		{
			p->matricula=novaMatricula;
			printf("Digite o nome da turma: ");
			scanf("%s\n",&nome);
			p->nome=nome;
			return NULL;
		}	
		else
			return alteraProfessor(nome, matricula, p->listaInscritos);
	}
	else
	{
		novaMatricula = 0;
		return NULL;
	}
}
struct professor *buscarProfessor(char nome[], int matricula, struct professor * p)
{
	if (novaMatricula!=0)
		scanf("%d",&novaMatricula);
	if (p)
		if ((novaMatricula==p->matricula))
			return *p;
		else
			return buscaProfessor(nome, matricula, p->listaInscritos);
	else
		{
			novaMatricula = 0;
			return NULL;
		}
}
struct professor *listarProfessor(struct professor *p)
{
	if (p)
		return p;
	else
		return NULL;
}
