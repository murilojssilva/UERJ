/* SOMA VETORIAL - VERSÃO PARALELA - OMP

 Argumentos de linha de comando:
 
 ./soma_vet_seq <tamanho> <arquivo de entrada A> <arquivo de entrada B> <arquivo de saída>
 
*/

#include <stdio.h>
#include <stdlib.h>

double * le_vetor(FILE * fp, int tamanho);

double * soma_vet(int tamanho, double *a, double *b);

void escreve_vetor(FILE * fp, int tamanho, double *v);

int main(int argc, char **argv)
{

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


    a = le_vetor(inpA, tamanho);
    b = le_vetor(inpB, tamanho);
    c = soma_vet(tamanho,a,b);
    
    escreve_vetor(out,tamanho,c);
    
    fclose(inpA);
    fclose(inpB);
    fclose(out);
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
    
    #pragma omp parallel for
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

