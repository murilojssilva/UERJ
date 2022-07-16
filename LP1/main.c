#include <stdio.h>
#include <stdlib.h>

#define TAM 100

main()
{
	FILE *entrada, *saida;
char entrada[TAM], saida[TAM];      
int  menuPrincipal;
int  menuTurmas, menuAlunos, menuProfessores;

do
{

 printf("--------MENU-------\n");
 printf("1-T- Turmas\n");
 printf("2-A- Alunos\n");
 printf("3-P- Professores\n");
 printf("4-S- Salvar Arquivo");
 printf("5-Q- Sair");
 printf("\nDigite 1, 2, 3 ou 4 (5 para sair):");
 scanf ("%d", &menuPrincipal);
 
 switch (menuPrincipal)
 {
    case 1:
    	printf("--------MENU TURMAS-------\n");
 		printf("1- Criar Turma\n");
 		printf("2- Excluir Turma\n");
 		printf("3- Alterar Turma\n");
 		printf("4- Buscar Turma\n");
 		printf("5- Inscrever aluno\n");
 		printf("6- Remover aluno da turma\n");
 		printf("7- Listar turmas\n");
 		printf("\nDigite sua opcao (V para voltar ao menu principal):");
 		scanf ("%d", &menuTurmas);
 		
 		switch (menuTurmas)
 		{
    	 case 1:
         	fflush(stdin);
         	fscanf("%s",turma.nome);
         	gets(gite a matricula do professor: ");
         	fflush (stdin);
         	scanf("%f",&turma.professor);
			printf("\nDigite a quantidade de vagas:");
         	fflush (stdin);
         	scanf("%f",&turma.vagas);
         	
       	 break;
       	    
   		 case 2:
            // chamada da função excluir turma
         break;
         
    	 case 3:
           // chamada da função alterar turma
         break;
         
         case 4:
           // chamada da função buscar turma
         break;
         
         case 5:
           // chamada da função inscrever aluno
         break;
         
         case 6:
           // chamada da função remover aluno
         break;
         
         case 7:
        
    	printf("\nNome da Turma: %s",turma.nome);
    	printf("\nNome do professor: %d",turma.professor);
    	printf("\nQuantidade de vagas: %c\n\n",turma.vaga);
    
   	break;
	}
    case 2:
        printf("--------MENU ALUNOS-------\n");
 		printf("1- Cadastrar aluno\n");
 		printf("2- Excluir aluno\n");
 		printf("3- Alterar aluno\n");
 		printf("4- Buscar aluno\n");
 		printf("5- Listar aluno\n");
 		printf("\nDigite sua opcao (V para voltar ao menu principal):");
 		scanf ("%d", &menuAlunos);
 		
 		switch (menuAlunos)
 		{
    	 case 1:
        	printf("\nDigite o nome do aluno:");
         	fflush(stdin);
         '	gets(aluno.nome);
         	printf("\nDigite a matricula do aluno: ");
         	fflush (stdin);
         	scanf("%f",&aluno.matricula);
         	
       	 break;
       	 
   		 case 2:
            // chamada da função excluir aluno
         break;
         
    	 case 3:
            // chamada da função alterar aluno
         break;
         
         case 4:
            // chamada da função buscar aluno
         break;
         
         case 5:
            // chamada da função listar aluno
         break;
    break;
        }
    case 3:
        printf("--------MENU Professores-------\n");
 		printf("1- Cadastrar professor\n");
 		printf("2- Excluir professor\n");
 		printf("3- Alterar professor\n");
 		printf("4- Buscar professor\n");
 		printf("5- Listar professor\n");
 		printf("\nDigite sua opcao (V para voltar ao menu principal):");
 		scanf ("%d", &menuProfessores);
 		
 		switch (menuProfessores)
 		{
    	 case 1:
    	 	FILE *ofessor:");
         	gets(professor.nome);
         '	printf("\nDigite a matricula do professor: ");
         	fflush (stdin);
         	scanf("%f",&professor.matricula);
         	fclose(armazena);                
   		 case 2:
            // chamada da função excluir professor
         break;
         
    	 case 3:
           // chamada da função alterar professor
         break;
         
         case 4:
            // chamada da função buscar professor
         break;
         
         case 5:
            // chamada da função listar professor
         break;
    break;
         }
	case 4:
    	
		printf("--------MENU SALVAR-------\n");
 		printf("1- Salvar Turma\n");
 		printf("2- Salvar Aluno\n");
 		printf("3- Salvar Professor\n");
 		printf("\nDigite sua opcao (V para voltar ao menu principal):");
 		
		scanf ("%d", &menuSalvar);
		
 		switch (menuSalvar)
	
		case 1:
		
		FILE *file;
		
		file=fopen("Turma.bin","a");
		
		fclose(file);
	
		case 2:
		
		FILE *file;
		
		file=fopen("Aluno.bin","a");
		
		fclose(file);
	
		case 3:
		
		FILE *file;
		
		file=fopen("Professor.bin","a");
		
		fclose(file);

       break;
       
    case 5:
       return 0;
    default:
       printf ("Tecla errada!!!\n");
 }
}
while (menuPrincipal != 5);
printf("\n\n");
system("pause");           
}
