/* SOMA VETORIAL - VERSÃO SEQUENCIAL

 Argumentos de linha de comando:
 
 ./soma_vet_seq <tamanho> <arquivo de entrada A> <arquivo de entrada B> <arquivo de saída>
 
*/

#include <stdio.h>
#include <stdlib.h>
#include "mytime.h"
#include <omp.h>

// PARA LIMITAR O NUMERO DE CORES
#define __USE_GNU
#include <sched.h>
#undef __USE_GNU
#include <errno.h>
//**************************

#ifdef PROC_PESADO
#include <math.h>

double f(double x);
#endif

double * le_vetor(FILE * fp, int tamanho);

double * soma_vet(int tamanho, double *a, double *b, int x);

void escreve_vetor(FILE * fp, int tamanho, double *v);

int main(int argc, char **argv)
{
#ifdef PROFILE
    double time;
    tic(&time,TIME_ms);
#endif
    FILE * inpA;
    FILE * inpB;
    FILE * out;
    
    int tamanho;
    
    double *a, *b, *c;
    
    if (argc != 6)
    {
        fprintf(stderr, "Argumentos inválidos! %s <tamanho> <arquivo de entrada A> <arquivo de entrada B> <arquivo de saída> <num threads>\n", argv[0]);
        exit(1);
    }
    int x = atoi(argv[5]);
    #ifdef _OPENMP
    omp_set_num_threads(x);
    #endif
    tamanho = atoi(argv[1]);

    cpu_set_t affinity_mask;
	// zera a mascara
    CPU_ZERO(&affinity_mask);
	// seta os bits
    CPU_SET(0, &affinity_mask);	
    CPU_SET(1, &affinity_mask);
	// aplica
    if (sched_setaffinity(0, sizeof(affinity_mask), &affinity_mask) < 0) 
	perror("Deu pau na afinidade");
    
    if ((inpA = fopen(argv[2],"r")) == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo %s de leitura\n", argv[2]);
        exit(1);
    }
    
    if ((inpB = fopen(argv[3],"r")) == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo %s de leitura\n", argv[3]);
        exit(1);
    }
    
    if ((out = fopen(argv[4],"w")) == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo %s de escrita\n", argv[4]);
        exit(1);
    }
#ifdef PROFILE
    tac(&time,TIME_ms);
    printf("[PROFILE] Inicializacao: %lf\n",time);
    
    tic(&time, TIME_ms);
#endif
    
    a = le_vetor(inpA, tamanho);
    
#ifdef PROFILE
    tac(&time,TIME_ms);
    printf("[PROFILE] LeituraA: %lf\n",time);
    
    tic(&time, TIME_ms);
#endif
    
    b = le_vetor(inpB, tamanho);
    
#ifdef PROFILE
    tac(&time,TIME_ms);
    printf("[PROFILE] LeituraB: %lf\n",time);
    
    tic(&time, TIME_ms);
#endif
    
    c = soma_vet(tamanho,a,b,x);
    
#ifdef PROFILE
    tac(&time,TIME_ms);
    printf("[PROFILE] Soma: %lf\n",time);
    
    tic(&time, TIME_ms);
#endif
    
    escreve_vetor(out,tamanho,c);
    
#ifdef PROFILE
    tac(&time,TIME_ms);
    printf("[PROFILE] Escrita: %lf\n",time);
    
    tic(&time, TIME_ms);
#endif
    
    free(a);
	free(b);
	free(c);
    fclose(inpA);
    fclose(inpB);
    fclose(out);
    
#ifdef PROFILE
    tac(&time,TIME_ms);
    printf("[PROFILE] Finalizacao: %lf\n",time);
#endif
}


double * le_vetor(FILE * fp, int tamanho)
{
    double * v = (double *) malloc(tamanho * sizeof(double));
    
    int i,tmp;
    for (i=0; i<tamanho; i++)
        tmp=fscanf(fp, "%lf\n", &v[i]);
    
    return v;
}

double * soma_vet(int tamanho, double *a, double *b, int x)
{
    double * v = (double *) malloc(tamanho * sizeof(double));
    
    int i;
    
    #pragma omp parallel for //num_threads(x)
    for (i=0; i<tamanho; i++)
    {
        #ifdef PROC_PESADO
        v[i]=f(a[i])+f(b[i]);
        #else
        v[i]=a[i]+b[i];
        #endif
    }
    
    return v;
    
}

void escreve_vetor(FILE * fp, int tamanho, double *v)
{
    int i;
    for (i=0; i<tamanho; i++)
        fprintf(fp, "%lf\n", v[i]);
    
}

#ifdef PROC_PESADO
double f(double x)
{
    x = abs(x);
    double y = 0;
    int i=0;
    
    while (i<(x*PROC_PESADO))
    {
        y+=sqrt(i);
        i++;
    }
    return y;
}
#endif