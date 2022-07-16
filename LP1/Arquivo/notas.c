#include <stdio.h>
//#include <cstdlib>
typedef struct
	{
		char nome[1000];
		int n1;
		int n2;
		float media;
	}func;
void main()
{
	FILE *file;
	file=fopen("notas.txt","w");
	func aluno;
	int i=0;
	float media_turma=0;
	for (;i<11;i++);
	{
		printf("Notas do aluno %d\n",i+1);
		scanf("%s",&aluno.nome[1000]);
		scanf("%d",&aluno.n1);
		scanf("%d",&aluno.n2);
		aluno.media=(aluno.n1+aluno.n2)/2;
		media_turma+=aluno.media;
		fprintf(file,"Notas do aluno: %s\nNota 1: %d\nNota 2: %d\nMedia: %f\n",aluno.nome,aluno.n1,aluno.n2,aluno.media);
	}
	media_turma/=10;
	fprintf(file,"\b%f",media_turma);
	fclose(file);
}

