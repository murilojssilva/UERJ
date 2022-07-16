//Murilo de Jesus e Pedro Marques
//Trabalho Final de Sistemas Operacionais

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include </usr/include/semaphore.h>
#include <string.h>
#include <math.h>

#define BUFFER 5
#define LC 1
#define LA 3
#define MM 4
#define DM 5
#define EA 3

int numLeituras=0;
sem_t nLeituras;

typedef struct
{
    char nomeArquivo[100];
    int ordem;
    double **A,**B,**C,**D,E;
} S;

typedef struct
{
     S buffer[BUFFER];
     int in,out;
     sem_t full,empty,mutex;
} SBuff;

SBuff shared[4];

void impMat(double ** M, int ordem, FILE * p);
void impMatStd(double ** M, int ordem);
double Determinant(double ** a, int n)
{
    int i,j,j1,j2;                
	double det=0;
	double **m = NULL;
	//if (n<1)    {exit(0);}
	else if (n==1) 
	{               
		det=a[0][0];
	}
	else if (n==2) 
	{                
		det=a[0][0]*a[1][1]-a[1][0]*a[0][1];
	}
    else
    {
		det=0;                      
		for (j1=0;j1<n;j1++) 
		{
			m=(double **) malloc((n-1)* sizeof(double *));
			for (i=0;i<n-1;i++)
				m[i]=(double *) malloc((n-1)* sizeof(double));
            for (i = 1;i<n; i++)
			{
				j2 = 0;              
				for (j=0;j<n;j++)
				{
					if (j == j1) continue;
					m[i-1][j2]=a[i][j];  
					j2++;                  
				}
			}
			det+=pow(-1.0,1.0+j1+1.0)*a[0][j1]*Determinant(m,n-1);
			for (i=0;i<n-1;i++) free(m[i]);
			free(m);                       
		}
	}
	return det;
}
double ** mMat(double ** a, double** b, int ordem)
{
	double **c=NULL;
	int i=0,j=0,k=0;
	c=(double**) malloc(sizeof(double*)*ordem);
	for(i = 0; i < ordem; i++)
	{
		c[i] = (double *) malloc(sizeof(double)*ordem);
	}
	for(i=0;i<ordem;i++)
	{
		for(j=0;j<ordem;j++)
		{
			c[i][j]=0;
			for(k = 0;k<ordem;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	return c;
}
void* leitoraCatalogo(void* arg)
{
	FILE * entrada;
	char arq[100];
	entrada=fopen((char*)arg, "r");
    while(1)
    {
        if(fscanf(entrada,"%s\n",arq)==EOF) break;
        numLeituras++;    
		S * itemArq=(S*)malloc(sizeof(S));
		strcpy((*itemArq).nomeArquivo,arq);
        sem_wait(&shared[0].empty);
        sem_wait(&shared[0].mutex);
        shared[0].buffer[shared[0].in]=*itemArq; 
        shared[0].in=(shared[0].in+1)%BUFFER;
        sem_post(&shared[0].mutex);
        sem_post(&shared[0].full);
        free(itemArq);
    }
    fclose(entrada);
    return NULL;
}
void* leitoraArq(void* arg)
{
	S * item;
	FILE * arquivoMat;
	int ordem;
	while(1)
    {
		double ** A, **B;
		int i, j;
		item=(S*)malloc(sizeof(S));
		sem_wait(&shared[0].full);
		sem_wait(&shared[0].mutex);
		*item=shared[0].buffer[shared[0].out];
		shared[0].out=(shared[0].out+1)%BUFFER;
		sem_post(&shared[0].mutex);
		sem_post(&shared[0].empty);
		arquivoMat=fopen((*item).nomeArquivo, "r");
		fscanf(arquivoMat,"%d\n",&ordem);
		A=(double**) malloc(sizeof(double*) * ordem);
		B=(double**) malloc(sizeof(double*) * ordem);
		for(i=0;i<ordem;i++)
		{
			A[i]=(double *) malloc(sizeof(double) * ordem);
			B[i]=(double *) malloc(sizeof(double) * ordem);
		}
		for(i=0;i<ordem;i++)
		{
			for(j=0;j<ordem;j++)
				fscanf(arquivoMat, "%lf", &(A[i][j]) );
		}
		for(i = 0; i < ordem; i++)
		{
			for(j=0;j<ordem;j++)
				fscanf(arquivoMat, "%lf", &(B[i][j]));
		}
		fclose(arquivoMat);
		(*item).A=A;
		(*item).B=B;
		(*item).ordem=ordem;
		sem_wait(&shared[1].empty);
		sem_wait(&shared[1].mutex);
		shared[1].buffer[shared[1].in] = *item;
		shared[1].in = (shared[1].in+1)%BUFFER;
		sem_post(&shared[1].mutex);
		sem_post(&shared[1].full);
		free(item);
	}
    return NULL;
}
void* multiMat(void* arg)
{
	S * item;
	int ordem;
	while(1)
	{
		double **A, **B, ** C;
		int i, j;
		item=(S*) malloc(sizeof(S));
		sem_wait(&shared[1].full);
		sem_wait(&shared[1].mutex);
		*item=shared[1].buffer[shared[1].out];
		shared[1].out=(shared[1].out+1)%BUFFER;
		sem_post(&shared[1].mutex);
		sem_post(&shared[1].empty);
		A=(*item).A;
		B=(*item).B;
		ordem=(*item).ordem;
		C=mMat(A, B, ordem);
		(*item).C=C;
		sem_wait(&shared[2].empty);
		sem_wait(&shared[2].mutex);
		shared[2].buffer[shared[2].in] = *item;
		shared[2].in=(shared[2].in+1)%BUFFER;
		sem_post(&shared[2].mutex);
		sem_post(&shared[2].full);
		free(item);
	}
	return NULL;
}
void* determinanteMat(void* arg)
{
	S * item;
	int ordem;
	while(1)
	{
		double E, **C;
		int i, j;
		item=(S*) malloc(sizeof(S));
		sem_wait(&shared[2].full);
		sem_wait(&shared[2].mutex);
		*item=shared[2].buffer[shared[2].out];
		shared[2].out = (shared[2].out+1)%BUFFER;
		sem_post(&shared[2].mutex);
		sem_post(&shared[2].empty);
		ordem=(*item).ordem;
		C=(*item).C;
		E=Determinant(C, ordem);
		(*item).E=E;
		sem_wait(&shared[3].empty);
		sem_wait(&shared[3].mutex);
		shared[3].buffer[shared[3].in]=*item;
		shared[3].in = (shared[3].in+1)%BUFFER;
		sem_post(&shared[3].mutex);
		sem_post(&shared[3].full);
		free(item);
	}
	return NULL;
}
void* escreveArq(void* arg)
{
	S * item;
	FILE * arquivoMat;
	int ordem,indice= *(int*) arg;
	while(1)
	{
		double ** A, **B, **C, E;
		char* arq;
		int i, j;
		item=(S*) malloc(sizeof(S));
		sem_wait(&nLeituras);
		if(numLeituras==0)
		{
			sem_post(&nLeituras);
			pthread_exit(NULL);
		}
		--numLeituras;       
		sem_post(&nLeituras);
		sem_wait(&shared[3].full);
		sem_wait(&shared[3].mutex);
		*item=shared[3].buffer[shared[3].out];
		shared[3].out=(shared[3].out+1)%BUFFER;
		sem_post(&shared[3].mutex);
		sem_post(&shared[3].empty);
		A=(*item).A;
		B=(*item).B;
		C=(*item).C;
		E=(*item).E;
		arq=(*item).nomeArquivo;
		ordem=(*item).ordem;
		arquivoMat=fopen(strcat(arq, ".out"), "w");
		fprintf(arquivoMat, "============================================\n");
		fprintf(arquivoMat, "%s - %d\n", arq, ordem);
		fprintf(arquivoMat, "---------------------------\n");
		impMat(A, ordem, arquivoMat);
		fprintf(arquivoMat, "---------------------------\n");
		impMat(B, ordem, arquivoMat);
		fprintf(arquivoMat, "---------------------------\n");
		impMat(C, ordem, arquivoMat);
		fprintf(arquivoMat, "---------------------------\n");
		fprintf(arquivoMat, "%lf\n", E);
		fprintf(arquivoMat, "============================================\n");
		fclose(arquivoMat);
		free(item);
	}
	return NULL;
}
int main(int argc, char**argv)
{
	char * str=argv[1];
	pthread_t idLC, idLA[LA], idMM[MM], idDM[DM], idEA[EA];
	int i;
	sem_init(&nLeituras, 0, 1);
	for(i=0;i<4;i++)
	{
		sem_init(&shared[i].full,0,0);
		sem_init(&shared[i].empty,0,BUFFER);
		sem_init(&shared[i].mutex,0,1);
    }
	for(i=0;i<LC;i++)
		pthread_create(&idLC, NULL, leitoraCatalogo, str);
	for(i=0;i<LA;i++)
		pthread_create(&idLA[i], NULL, leitoraArq, NULL);
	for(i=0;i<MM;i++)
		pthread_create(&idMM[i], NULL, multiMat, NULL);
	for(i= 0;i<DM;i++)
		pthread_create(&idDM[i], NULL, determinanteMat, NULL);
	for(i= 0;i<EA;i++)
		pthread_create(&idEA[i], NULL, escreveArq, &i);
	for(i=0;i<EA;i++)
		pthread_join(idEA[i], NULL);
    return 0;
}
void impMat(double ** M, int ordem, FILE* p)
{
	int i,j;
	for(i=0;i<ordem;i++)
	{
		for(j=0;j<ordem;j++)
		{
			fprintf(p,"%lf ",M[i][j]);
		}
		fprintf(p,"\n");
	}
	fprintf(p,"\n");
}
/*void impMatStd(double ** M, int ordem)
{
	int i,j;
	for(i=0;i<ordem;i++)
	{
		for(j=0;j<ordem;j++)
		{
			printf("%lf ",M[i][j]);
		}
		printf( "\n");
	}
	printf("\n");
}*/
