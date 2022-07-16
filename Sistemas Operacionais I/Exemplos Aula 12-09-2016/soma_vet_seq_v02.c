/* SOMA VETORIAL - VERSÃO SEQUENCIAL

 Argumentos de linha de comando:
 
 ./soma_vet_seq <tamanho> <arquivo de entrada A> <arquivo de entrada B> <arquivo de saída>
 
*/

#include <stdio.h>
#include <stdlib.h>
#include "mytime.h"

double * le_vetor(FILE * fp, int tamanho);

double * soma_vet(int tamanho, double *a, double *b);

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
    
    if (argc != 5)
    {
        fprintf(stderr, "Argumentos inválidos! %s <tamanho> <arquivo de entrada A> <arquivo de entrada B> <arquivo de saída>\n", argv[0]);
        exit(1);
    }
    
    tamanho = atoi(argv[1]);
    
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
    
    c = soma_vet(tamanho,a,b);
    
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
    
    int i;
    for (i=0; i<tamanho; i++)
        fscanf(fp, "%lf\n", &v[i]);
    
    return v;
}

double * soma_vet(int tamanho, double *a, double *b)
{
    double * v = (double *) malloc(tamanho * sizeof(double));
    
    int i;
    
    for (i=0; i<tamanho; i++)
    {
        v[i]=a[i]+b[i];
    }
    
    return v;
    
}

void escreve_vetor(FILE * fp, int tamanho, double *v)
{
    int i;
    for (i=0; i<tamanho; i++)
        fprintf(fp, "%lf\n", v[i]);
    
}
