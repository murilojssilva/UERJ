


/**
*
*  Membros: Adrianno Sampaio e Beatriz Carvalho
*
**/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include </usr/include/semaphore.h>
#include <string.h>
#include <math.h>

#define BUFF 5
#define NLC 1
#define NLA 3
#define NMM 4
#define NDM 5
#define NEA 3

int numLeituras = 0;
sem_t nLeituras;

typedef struct{

    char arqNome[100];//nome do arquivo de entrada
    int ordem; // ordem das matrizes
    double **A; //matriz A
    double **B; //matriz B
    double **C; // matriz C
    double E; // determinante

} S;

typedef struct{

     S buffer[BUFF];
     int in;
     int out;
     sem_t full;
     sem_t empty;
     sem_t mutex;

} sbuf_t;

sbuf_t shared[4];

void impMat(double ** M, int ordem, FILE * p);

void impMatStd(double ** M, int ordem);

double Determinant(double ** a, int n){

    int i,j,j1,j2 ;                    // general loop and matrix subscripts
    double det = 0 ;                   // init determinant
    double **m = NULL ;                // pointer to pointers to implement 2d
                                       // square array

    if (n < 1)    {   }                // error condition, should never get here

    else if (n == 1) {                 // should not get here
        det = a[0][0] ;
        }

    else if (n == 2)  {                // basic 2X2 sub-matrix determinate
                                       // definition. When n==2, this ends the
        det = a[0][0] * a[1][1] - a[1][0] * a[0][1] ;// the recursion series
        }


                                       // recursion continues, solve next sub-matrix
    else {                             // solve the next minor by building a
                                       // sub matrix
        det = 0 ;                      // initialize determinant of sub-matrix

                                           // for each column in sub-matrix
        for (j1 = 0 ; j1 < n ; j1++) {
                                           // get space for the pointer list
            m = (double **) malloc((n-1)* sizeof(double *)) ;

            for (i = 0 ; i < n-1 ; i++)
                m[i] = (double *) malloc((n-1)* sizeof(double)) ;
                       //     i[0][1][2][3]  first malloc
                       //  m -> +  +  +  +   space for 4 pointers
                       //       |  |  |  |          j  second malloc
                       //       |  |  |  +-> _ _ _ [0] pointers to
                       //       |  |  +----> _ _ _ [1] and memory for
                       //       |  +-------> _ a _ [2] 4 doubles
                       //       +----------> _ _ _ [3]
                       //
                       //                   a[1][2]
                      // build sub-matrix with minor elements excluded
            for (i = 1 ; i < n ; i++) {
                j2 = 0 ;               // start at first sum-matrix column position
                                       // loop to copy source matrix less one column
                for (j = 0 ; j < n ; j++) {
                    if (j == j1) continue ; // don't copy the minor column element

                    m[i-1][j2] = a[i][j] ;  // copy source element into new sub-matrix
                                            // i-1 because new sub-matrix is one row
                                            // (and column) smaller with excluded minors
                    j2++ ;                  // move to next sub-matrix column position
                    }
                }

            det += pow(-1.0,1.0 + j1 + 1.0) * a[0][j1] * Determinant(m,n-1) ;
                                            // sum x raised to y power
                                            // recursively get determinant of next
                                            // sub-matrix which is now one
                                            // row & column smaller

            for (i = 0 ; i < n-1 ; i++) free(m[i]) ;// free the storage allocated to
                                            // to this minor's set of pointers
            free(m) ;                       // free the storage for the original
                                            // pointer to pointer
        }
    }
    return(det) ;

}

double ** mMat(double ** a, double** b, int ordem){
    double **c = NULL;
    int i = 0, j = 0, k = 0;

    c = (double**) malloc(sizeof(double*) * ordem);
    for(i = 0; i < ordem; i++){
        c[i] = (double *) malloc(sizeof(double) * ordem);
    }

    for(i = 0; i < ordem; i++){
        for(j = 0; j < ordem; j++){
            c[i][j]=0;
            for(k = 0; k < ordem; k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    return c;
}

void* leitoraCatalogo(void* arg){

    FILE * entrada;
    char arq[100];
    entrada = fopen((char*)arg, "r");
    while(1){

        if(fscanf(entrada, "%s\n", arq) == EOF) break;
        numLeituras++;

        //Produz item
         S * itemArq = (S*) malloc(sizeof(S));
        strcpy((*itemArq).arqNome, arq);

        //Seção Crítica
        // Verifica se há espaços em branco para guardar, senão espera
        sem_wait(&shared[0].empty);
        // se o buffer não está sendo utilizado bloqueia o mutex e acessa o buffer, se estiver, espera
        sem_wait(&shared[0].mutex);
        //printf("Produzi [%s]\n", arq);
        shared[0].buffer[shared[0].in] = *itemArq; // coloca item produzido no buffer
        shared[0].in = (shared[0].in+1)%BUFF;
        //Libera o buffer para uso
        sem_post(&shared[0].mutex);
        //incrementa o numero de espaços ocupados
        sem_post(&shared[0].full);
        //Fim Seção crítica

        free(itemArq);

    }

    fclose(entrada);
    return NULL;
}

void* leitoraArq(void* arg){


    S * item;
    FILE * arquivoMat;
    int ordem;

    while(1){

        double ** A, **B;
        int i, j;
        item = (S*) malloc(sizeof(S));
        //Verifica se há itens para serem consumidos
        sem_wait(&shared[0].full);
        //Verifica o mutex
        sem_wait(&shared[0].mutex);
        *item = shared[0].buffer[shared[0].out];
        shared[0].out = (shared[0].out+1)%BUFF;
        //libera mutex
        sem_post(&shared[0].mutex);
        //incrementa o num de espaços vazios
        sem_post(&shared[0].empty);

        arquivoMat = fopen((*item).arqNome, "r");// abre o arquivo contendo as matrizes
        fscanf(arquivoMat, "%d\n", &ordem); //Lê a ordem das matrizes
        //printf("Consumi [%s]\n", (*item).arqNome);
        //Aloca o espaço necessário para as matrizes
        A = (double**) malloc(sizeof(double*) * ordem);
        B = (double**) malloc(sizeof(double*) * ordem);
        for(i = 0; i < ordem; i++){
            A[i] = (double *) malloc(sizeof(double) * ordem);
            B[i] = (double *) malloc(sizeof(double) * ordem);
        }

        //inicializa os valores das matrizes
        for(i = 0; i < ordem; i++){
            for(j = 0; j < ordem; j++){
                fscanf(arquivoMat, "%lf", &(A[i][j]) );
            }
        }
        for(i = 0; i < ordem; i++){
            for(j = 0; j < ordem; j++){
                fscanf(arquivoMat, "%lf", &(B[i][j]) );
            }
        }
        fclose(arquivoMat);
        (*item).A = A;
        (*item).B = B;
        (*item).ordem = ordem;



        //esperando um espaço vazio no buffer
        sem_wait(&shared[1].empty);
        //esperando a liberação do mutex
        sem_wait(&shared[1].mutex);
        shared[1].buffer[shared[1].in] = *item;
        shared[1].in = (shared[1].in+1)%BUFF;
        //liberando buffer
        sem_post(&shared[1].mutex);
        //acrescentando espaço vazio
        sem_post(&shared[1].full);

        free(item);

    }
    return NULL;
}

void* multiMat(void* arg){


    S * item;
    int ordem;
    while(1){

        double **A, **B, ** C;
        int i, j;
        item = (S*) malloc(sizeof(S));
        //Verifica se há itens para serem consumidos
        sem_wait(&shared[1].full);
        //Verifica o mutex
        sem_wait(&shared[1].mutex);
        *item = shared[1].buffer[shared[1].out];
        shared[1].out = (shared[1].out+1)%BUFF;
        //libera mutex
        sem_post(&shared[1].mutex);
        //incrementa o num de espaços vazios
        sem_post(&shared[1].empty);

        A = (*item).A;
        B = (*item).B;
        ordem = (*item).ordem;
        C = mMat(A, B, ordem);

        (*item).C = C;

        //esperando um espaço vazio no buffer
        sem_wait(&shared[2].empty);
        //esperando a liberação do mutex
        sem_wait(&shared[2].mutex);
        shared[2].buffer[shared[2].in] = *item;
        shared[2].in = (shared[2].in+1)%BUFF;
        //liberando buffer
        sem_post(&shared[2].mutex);
        //acrescentando espaço vazio
        sem_post(&shared[2].full);
        free(item);

    }
    return NULL;
}

void* determinanteMat(void* arg){


    S * item;
    int ordem;
    while(1){

        double E, ** C;
        int i, j;
        item = (S*) malloc(sizeof(S));
        //Verifica se há itens para serem consumidos
        sem_wait(&shared[2].full);
        //Verifica o mutex
        sem_wait(&shared[2].mutex);
        *item = shared[2].buffer[shared[2].out];
        shared[2].out = (shared[2].out+1)%BUFF;
        //libera mutex
        sem_post(&shared[2].mutex);
        //incrementa o num de espaços vazios
        sem_post(&shared[2].empty);


        ordem = (*item).ordem;
        //inicializa os valores das matrizes
        C = (*item).C;
        E = Determinant(C, ordem);
        (*item).E = E;


        //esperando um espaço vazio no buffer
        sem_wait(&shared[3].empty);
        //esperando a liberação do mutex
        sem_wait(&shared[3].mutex);
        shared[3].buffer[shared[3].in] = *item;
        shared[3].in = (shared[3].in+1)%BUFF;
        //liberando buffer
        sem_post(&shared[3].mutex);
        //acrescentando espaço vazio
        sem_post(&shared[3].full);
        free(item);

    }
    return NULL;
}

void* escreveArq(void* arg){


    S * item;
    FILE * arquivoMat;
    int ordem, indice = *(int*) arg;

    while(1){

        double ** A, **B, **C, E;
        char* arq;
        int i, j;
        item = (S*) malloc(sizeof(S));

        //Verifica o mutex
        sem_wait(&nLeituras);
        if(numLeituras == 0){
            sem_post(&nLeituras);
            pthread_exit(NULL);
        }
        --numLeituras;
        //libera mutex
        sem_post(&nLeituras);



        //Verifica se há itens para serem consumidos
        sem_wait(&shared[3].full);
        //Verifica o mutex
        sem_wait(&shared[3].mutex);
        *item = shared[3].buffer[shared[3].out];
        shared[3].out = (shared[3].out+1)%BUFF;
        //libera mutex
        sem_post(&shared[3].mutex);
        //incrementa o num de espaços vazios
        sem_post(&shared[3].empty);


        A = (*item).A ;
        B = (*item).B ;
        C = (*item).C ;
        E = (*item).E ;
        arq = (*item).arqNome;
        ordem = (*item).ordem;

        /*
        printf( "============================================\n");
        printf( "%s - %d\n", arq, ordem);
        printf( "---------------------------\n");
        impMatStd(A, ordem);
        printf( "---------------------------\n");
        impMatStd(B, ordem);
        printf( "---------------------------\n");
        impMatStd(C, ordem);
        printf( "---------------------------\n");
        printf( "%lf\n", E);
        printf( "============================================\n");
        */


        arquivoMat = fopen(strcat(arq, ".out"), "w");// abre o arquivo de saída
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

int main(int argc, char**argv){

    char * str = argv[1];
    pthread_t idLC, idLA[NLA], idMM[NMM], idDM[NDM], idEA[NEA];
    int i;

    sem_init(&nLeituras, 0, 1);
    for(i = 0; i < 4; i++){ //inicializando os semáforos para cada posição do array shared
        sem_init(&shared[i].full, 0, 0);
        sem_init(&shared[i].empty, 0, BUFF);
        sem_init(&shared[i].mutex, 0, 1);
    }

    for(i = 0; i < NLC; i++)
        pthread_create(&idLC, NULL, leitoraCatalogo, str);
    for(i = 0; i < NLA; i++)
        pthread_create(&idLA[i], NULL, leitoraArq, NULL);
    for(i = 0; i < NMM; i++)
        pthread_create(&idMM[i], NULL, multiMat, NULL);
    for(i = 0; i < NDM; i++)
        pthread_create(&idDM[i], NULL, determinanteMat, NULL);
    for(i = 0; i < NEA; i++)
        pthread_create(&idEA[i], NULL, escreveArq, &i);


    for(i = 0; i < NEA; i++){

        pthread_join(idEA[i], NULL);

    }

    //sleep(5);

    return 0;

}

void impMat(double ** M, int ordem, FILE* p){
    int i, j;
    for(i = 0; i < ordem; i++){
        for(j = 0; j < ordem; j++){
            fprintf(p, "%lf ", M[i][j]);
        }
        fprintf(p, "\n");
    }
    fprintf(p, "\n");
}

void impMatStd(double ** M, int ordem){
    int i, j;
    for(i = 0; i < ordem; i++){
        for(j = 0; j < ordem; j++){
            printf("%lf ", M[i][j]);
        }
        printf( "\n");
    }
    printf("\n");
}


