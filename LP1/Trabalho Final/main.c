#include <stdio.h>
#include <stdlib.h>
#include "auxiliar.h"
#include "professor.h"
#include "turma.h"
#include "aluno.h"
#define TAM 100
char  MPrin;
struct turma
{
        char nome[TAM];
        int professor;
        int vagas;
        int qtdInscritos;
        struct turma *listaInscritos;
};

struct professor
{
	char nome[TAM];
	int matricula;
	struct professor *listaInscritos;
};

struct aluno
{
	char nome[TAM];
	int matricula;
	struct aluno *listaInscritos;
};

char MenuPrincipal(char MPrin);

void main()
{
	menuPrincipal(MPrin);
}

