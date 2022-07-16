#include <stdio.h>
#include <stdlib.h>
#include "auxiliar.h"
#include "professor.h"
#include "aluno.h"
#include "turma.h"
char MPrin;
char MTurm, MAlun, MProf;
char MenuTurmas(char MTurm)
{
   	printf("\n\n*********************************");
	printf("\n*        MENU TURMAS            *\n");
	printf("*********************************\n");
	printf("*  [1] - CRIAR TURMA	        *\n");
	printf("*  [2] - EXCLUIR TURMA        	*\n");
	printf("*  [3] - ALTERAR TURMA    	*\n");
	printf("*  [4] - BUSCAR TURMA         	*\n");
	printf("*  [5] - INSCREVER ALUNO	*\n");
	printf("*  [6] - REMOVER ALUNO DA TURMA	*\n");
	printf("*  [7] - LISTAR TURMAS		*\n");
	printf("*  [V] - VOLTAR AO MENU INICIAL *\n");
	printf("*********************************\n");
	printf("Digite o Menu deseja acessar: ");
 	scanf ("%c", &MTurm);
 	switch (MTurm)
 	{
 		case '1':
 			criaTurma(nome,professor,vagas,p,)
			insereTurma(nome,professor,vagas,t,p);
			menuPrincipal(MPrin);
 			break;
 		case '2':
 			excluiTurma(nome,matricula,vagas,qtdInscritos,t,p);
 			menuPrincipal(MPrin);
 			break;
 		case '3':
 			alteraTurma(nome,matricula,vagas,qtdInscritos,professor,t,p);
 			menuPrincipal(MPrin);
 			break;
 		case '4':
 			buscarTurma(nome,matricula,p,t);
 			menuPrincipal(MPrin);
 			break;
 		case '5':
 			inserirAlunoTurma(nome,matricula,t,a);
 			menuPrincipal(MPrin);
 			break;
 		case '6':
 			buscarAlunoTurma(matricula,t,a);
 			menuPrincipal(MPrin);
 			break;
 		case '7':
 			listarTurmas(t);
 			menuPrincipal(MPrin);
 			break;
 		case 'V':
 			menuPrincipal(MPrin);
 			break;
 		default:
 			printf("Digite novamente");
 			MenuTurmas(MTurm);
 			break;
}

char MenuAlunos(char MALun)
{
	printf("\n\n*********************************");
	printf("\n*        MENU ALUNOS            *\n");
	printf("*********************************\n");
	printf("*  [1] - CADASTRAR ALUNO        *\n");
	printf("*  [2] - EXCLUIR ALUNO        	*\n");
	printf("*  [3] - ALTERAR ALUNO    	*\n");
	printf("*  [4] - BUSCAR ALUNO         	*\n");
	printf("*  [5] - LISTAR ALUNOS	        *\n");
	printf("*  [V] - VOLTAR AO MENU INICIAL *\n");
	printf("*********************************\n");
	printf("Digite o Menu deseja acessar: ")
 	scanf ("%c", &MAlun);
 	switch(MAlun)
 	{
 		case '1':
 			criarAluno(nome,matricula);
			inserirAluno(nome,matricula,a);
			break;
		case '2':
			excluiAluno(nome,matricula,a);
			libera(aux);
			break;
		case '3':
			alteraAluno(nome,matricula,a);
			break;
		case '4':
			buscaAluno(nome,matricula,a);
			break;
		case '5':
			listarAluno(a);
			break;
		case 'V':
			MenuPrincipal(MPrin);
			break;
		default:
			printf("Digite novamente");
			MenuAlunos(MAlun);
			break;
}

char MenuProfessores(char MProf)
{
	printf("\n\n*********************************");
	printf("\n*        MENU PROFESSORES       *\n");
	printf("*********************************\n");
	printf("*  [1] - CADASTRAR PROFESSOR    *\n");
	printf("*  [2] - EXCLUIR PROFESSOR   	*\n");
	printf("*  [3] - ALTERAR PROFESSOR    	*\n");
	printf("*  [4] - BUSCAR PROFESSOR      	*\n");
	printf("*  [5] - LISTAR PROFESSORES	*\n");
	printf("*  [V] - VOLTAR AO MENU INICIAL *\n");
	printf("*********************************\n");
	printf("Digite o Menu deseja acessar: ");
	scanf ("%c", &MProf);
	switch (MProf)
	{
		case '1':
 			criaProfessor(nome,matricula);
			insereProfessor(nome,matricula,p);
			break;
		case '2':
			excluiProfessor(nome,matricula,p);
			liberar(exc);
			break;
		case '3':
			alteraProfessor(nome,matricula,p);
			break;
		case '4':
			buscarProfessor(nome,matricula,p);
			break;
		case '5':
			listarProfessor(p);
			break;
		case 'V':
			MenuPrincipal(MPrin);
			break;
		default:
			printf("Digite novamente");
			MenuProfessores(MProf);
			break;
	}
}

char MenuPrincipal(char MPrin)
{
 	printf("\n\n*********************************");
	printf("\n*        MENU PRINCIPAL         *\n");
	printf("*********************************\n");
	printf("*  [T] - TURMA			*\n");
	printf("*  [A] - ALUNOS			*\n");
	printf("*  [P] - PROFESSORES    	*\n");
	printf("*  [Q] - SAIR			*\n");
	printf("*********************************\n");
	printf("Digite o Menu deseja acessar: ");
 	scanf("%c",&MPrin);
 	switch (MPrin)
 	{
 		case 'T':
 			MenuTurmas(MTurm);
 			break;
 		case 'A':
 			MenuAlunos(MAlun);
 			break;
 		case 'P':
 			MenuProfessores(MProf);
 			break;
 		case 'Q':
 			return EOF;
			break;
		default:
			printf("Digite novamente");
			menuPrincipal(MPrin);
			break;
	}	
}

