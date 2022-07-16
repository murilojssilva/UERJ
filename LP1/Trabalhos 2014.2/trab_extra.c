#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Item
{
    char * palavra;
    int * linha;
    struct Item * pEsq;
    struct Item * pDir;
} Item;
 
void insere(struct Item ** , struct Item *, char*, int, int );
void InsereNumLinha(int * , int );
void Apresenta(struct Item* );
void Libera(struct Item*);
 
int main()
{
    int tamArq=0, numLinha=1, numLinhasArq=0;
    char nomeArq[50], c;
    scanf("%s", nomeArq);
    //strcpy(nomeArq,"ent.txt");
    FILE * pArq;
    pArq=fopen(nomeArq,"r");
    if (pArq==NULL) exit(1);
    /*Verifica o tamanho do arquivo de entrada*/
    while ((c=fgetc(pArq))!=EOF)
    {
        tamArq++;
        if (c=='\n') numLinhasArq++;
    }
    //printf("%d", tamArq);
    char * strPalavras=(char *) malloc(tamArq);
    char * strPalavrasOrig=strPalavras;
    char * palavra=strPalavras;
    struct Item * T=NULL, * novoItem=NULL;
    fseek(pArq,0, SEEK_SET);
    while ((c=fgetc(pArq))!=EOF)
    {
        //Converte para uppercase se estiver na faixa de letras minúsculas:
        if (c=='ç') c='C';
        if (c=='ã') c='A';
        if (c=='õ') c='O';
        if (c=='Ç') c='C';
        if (c=='Ã') c='A';
        if (c=='Õ') c='O';
        if (c=='á') c='A';
        if (c=='é') c='E';
        if (c=='í') c='I';
        if (c=='ó') c='O';
        if (c=='ú') c='U';
        if (c=='Á') c='A';
        if (c=='É') c='E';
        if (c=='Í') c='I';
        if (c=='Ó') c='O';
        if (c=='Ú') c='U';
        if (c=='à') c='A';
        if (c=='À') c='A';
        if (c=='ê') c='E';
        if (c=='Ê') c='E';
        if (c=='ô') c='O';
        if (c=='Ô') c='O';
        if (c=='â') c='A';
        if (c=='Â') c='A';
 
 
        c=(c>96&&c<123)?c-' ':c;
 
        if (!(c>64 && c<91))
        {
            strPalavras[0]='\0';
            novoItem=(struct Item*) calloc(1, sizeof(struct Item));
            if (strcmp(palavra,"")>0) insere(&T, novoItem, palavra, numLinha, numLinhasArq);
            //printf("%s\n", palavra);
            strPalavras++;
            palavra=strPalavras;
            if (c=='\n') numLinha++;
        }
        else
        {
            strPalavras[0]=c;
            strPalavras++;
        }
    }
    Apresenta(T);
    Libera(T);
    free(strPalavrasOrig);
    return 0;
}
 
void insere(struct Item ** T, struct Item * novoItem, char * palavra, int numLinha, int numLinhasArq)
{
    if (*T==NULL)
    {
        (*novoItem).palavra=palavra;
        int * vNumLinha=(int*) calloc(numLinhasArq, sizeof(int));
        vNumLinha[0]=numLinha;
        (*novoItem).linha=vNumLinha;
        *T=novoItem;
    }
    else
    {
        if (strcmp((**T).palavra,palavra)==0)
        {
            InsereNumLinha((**T).linha, numLinha);
        }
        else
        {
            if (strcmp((**T).palavra, palavra)<0)
            {
                insere( &(**T).pDir, novoItem, palavra, numLinha, numLinhasArq);
            }
            else
            {
                insere( &(**T).pEsq, novoItem, palavra, numLinha, numLinhasArq);
            }
        }
    }
}
 
void InsereNumLinha(int * vlinhas, int numLinha)
{
    int * vlinhasTemp=vlinhas;
    int iTemp=0;
    while (*(vlinhasTemp)!= NULL)
    {
        if ((*vlinhasTemp)==numLinha) return;
        vlinhasTemp++;
    }
    //vlinhasTemp--;
    (*vlinhasTemp)=numLinha;
    while ((vlinhasTemp>vlinhas) && (*(vlinhasTemp)-1>(*vlinhasTemp)))
    {
        iTemp=(*vlinhasTemp-1);
        *(vlinhasTemp-1)=*(vlinhasTemp);
        *(vlinhasTemp)=iTemp;
    }
}
 
void Apresenta(struct Item* T)
{
    if ((*T).pEsq!=NULL) Apresenta((*T).pEsq);
    if (T!=NULL)
    {
        printf("%s: ", (*T).palavra);
        int i=0;
        while((*T).linha[i]!= NULL)
        {
            if (i==0)
                printf("%d", (*T).linha[i]);
            else
                printf(", %d", (*T).linha[i]);
            i++;
        }
        printf("\n");
    }
    if ((*T).pDir!=NULL) Apresenta((*T).pDir);
}
 
void Libera(struct Item* T)
{
    if ((*T).pEsq!=NULL) Libera((*T).pEsq);
    if ((*T).pDir!=NULL) Libera((*T).pDir);
    if (T!=NULL)
    {
        free((*T).linha);
        free(T);
    }
}
