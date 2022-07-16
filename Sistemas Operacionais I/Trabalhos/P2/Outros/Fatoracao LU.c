//Resolucao de sistemas lineares utilizando o metodo da fatoracao LU com pivoteamento parcial
//Luiz Vinicius Soglia - lvmsoglia@hotmail.com

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//==========================================================================================================

//troca na str o caractere ca pelo caractere cb

void troca_caractere (char *str, const char ca, const char cb)
{
     int n, i;
     n = strlen(str);
     for (i=0; i<n; i++)
     {
         if (str[i] == ca)
         {str[i] = cb;}
     }
}

//==========================================================================================================

//funcao que implementa a resolução de sistemas lineares pela fatoracao LU com pivoteamento parcial

//n: é a ordem do sistema.
//matriz a[][]: 
//é a matriz dos coeficientes. Ao final do metodo ela guardara a matriz LU, com L abaixo da diagonal principal e U nas outras posicoes.
//matriz b[]: é a matriz dos termos independentes.
//matriz x[]: guarda os valores das variaveis após a resolução.

//retorna 0 caso haja sucesso, 1 para erros de entrada de argumentos invalidos, e 2 para erros de divisão por zero.

int fatoracao_LU (int n, float a[][n], float b[], float x[])
{
    
    int k, i, j, posl, erro;
    float m, soma, aux, pivo, y[n];
    
    if (n<2)
    {return 1;} //a ordem do sistema tem que ser maior ou igual a 2
    
    for (i=0; i<n; i++) //inicializa as variaveis x (por precaução)
    {x[i]=0;}

    erro=0; //A variavel erro se tornara 1 caso haja erros de divisao por zero

        //pivoteamento parcial
        for (k=0; k<(n-1); k++)
        {
            pivo=fabs(a[k][k]); //pivo inicial
            posl=k; //posicao da linha do pivo
            for (i=k+1; i<n; i++)
            {
                if (fabs(a[i][k])>pivo)
                {
                    pivo=fabs(a[i][k]); //passa a ser o novo pivo
                    posl=i; //guarda a posicao da linha do maior pivo
                }
            }
            if (posl!=k) //caso o pivo nao esteja na linha k, troca linha k pela linha posl
            {
                for (j=0; j<n; j++)//permuta as linhas da matriz a[][]
                {
                    aux=a[k][j];
                    a[k][j]=a[posl][j];
	                a[posl][j]=aux;
                }
                aux=b[k]; //tambem permuta as linhas da matriz b[]
                b[k]=b[posl];
                b[posl]=aux;
            }
            //Triangularizacao da matriz a[][], para a obtenção da matriz LU
	        if (a[k][k] != 0.0) //Evita erros de divisao por zero, caso o pivo seja zero
	        {
                for (i=k+1; i<n; i++)
                {
                    m = a[i][k]/a[k][k]; //calcula o multiplicador
                    //guarda os multiplicadores nas posicoes que deveriam ser zeradas.
                    //Assim a matriz a[][] guarda L abaixo da diagonal principal e guarda U no restante das posicoes. Isso economiza memoria
                    a[i][k] = m;
                    
                    for (j=k+1; j<n; j++) //comeca do elemento apos o valor a ser zerado (que na verdade esta guardando os multiplicadores)
                    {
                        a[i][j] = a[i][j] - (m*a[k][j]);
                    }
                }
            }
            else
            {erro = 1; break;} //Houve erro de divisão por zero
        }

    if (erro == 1) //Houve erro de divisão por zero. Retorna 2, indicando esse erro.
    {return 2;}
    
    //Resolve o sistema L Y = B, obtendo Y
    k=0;
    for (i=0; i<n; i++)
    {
        soma=0.0;
        for (j=0; j<i; j++)
        {
            soma = soma + y[j]*a[i][j]; //a[i][j] neste caso guarda os multiplicadores m (os termos abaixo da diagonal principal da matriz L)
        }
        y[k] = b[i] - soma;
        k++;
    }
    
    //Resolve o sistema U X = Y, obtendo X, utilizando o metodo da resolucao de um sistema triangular superior
    if (a[n-1][n-1] != 0.0)
    {x[n-1] = y[n-1] / a[n-1][n-1];}
    else
    {return 2;} //erro de divisão por zero

    for (i=n-2; i>-1; i--)
    {
        soma = 0.0;
        for (j=i+1; j<n; j++)
        {soma = soma + a[i][j]*x[j];}

        if (a[i][i] != 0)
        {x[i] = (y[i] - soma)/a[i][i];}
        else
        {return 2;} //erro de divisão por zero
     }

   return 0;
}

//==========================================================================================================

//Função principal

int main()
{
    int n, i, j, carregamento, teste;
    char op, nome_arq[260], buffer[64];
    FILE *fp;

    do
    {
        printf ("Resolucao de sistemas lineares utilizando fatoracao LU com pivoteamento parcial\n\n");
        do
        {
            printf ("Digite a ordem do sistema (n), no maximo n=100: ");
            fflush(stdin); scanf ("%d",&n);
        }
        while (n < 2 || n > 100);

        printf ("\nDigite a opcao para o carregamento do sistema linear:\n\n[1] Digitar os dados aqui\n[2] Atraves de um arquivo .txt\n\n");
        do
        {
            printf ("Opcao: ");
            fflush(stdin); scanf ("%d",&carregamento);
        }
        while (carregamento < 1 || carregamento > 2);

        //Cria as matrizes
        float a[n][n], x[n], b[n]; //cria as matrizes dos coeficientes (A), das variaveis (X) e dos termos independentes (B)

        //faz o carregamento da matriz do sistema de acordo com a opcao escolhida
        switch (carregamento)
        {

        case 1: //digita a matriz
        for (i=0; i<n; i++)
        {
            do
            {
                system ("cls");
                printf ("Digite os elementos da linha %d:\n\n", i+1);
                for (j=0; j<n; j++)
                {
                    printf ("a[%d][%d] = ", i+1, j+1);
                    scanf ("%f", &a[i][j]);
                }
                printf ("\nb[%d] = ", i+1);
                scanf ("%f", &b[i]);
                printf ("\nOs valores digitados estao corretos? (digite [S] para sim, ou [N] para nao): ");
                fflush(stdin); op = getchar();
            }
            while (op != 's' && op != 'S');
        }
        break;

        case 2: //carrega do arquivo
        do
        {
            printf ("\nDigite o caminho do arquivo de texto (com a extensao) que contem os dados:\n");
            fflush(stdin);
            scanf ("%259[^\n]",nome_arq);
            fp=fopen(nome_arq,"r");
            if (!fp)
            {
                printf ("\nErro na abertura do arquivo! Pressione [ENTER] para continuar\n");
                fflush(stdin); op = getchar();
            }
        }
        while(!fp);
        //inicializa e lê os coeficientes das matrizes A e B
        for (i=0; i<n; i++)
        {
            for (j=0; j<n; j++)
            {
                a[i][j]=0.0;
                fscanf (fp, "%f", &a[i][j]);
            }
            b[i]=0.0;
            fscanf (fp, "%f", &b[i]);
        }
        fclose(fp);
        break;

        default:
        printf ("\nOcorreu um erro no carregamento do sistema! Pressione [ENTER] para sair\n"); fflush(stdin); op = getchar(); return 0;

        } //fim do carregamento da matriz

        system ("cls");
        printf ("Dados carregados! Pressione [ENTER] para continuar e resolver o sistema linear\n");
        fflush(stdin); op = getchar(); system ("cls");

        //Chama a função que aplica o metodo da fatorcao LU
        teste = fatoracao_LU (n, a, b, x); //retorna zero para teste caso haja sucesso

        if (teste == 1) ///se a função retornar 1, argumentos invalidos foram passados para a função
        {
            printf ("Erro! Argumentos invalidos foram digitados!\n\nPressione [ENTER] para sair\n");
            fflush(stdin); op = getchar(); return 0;
        }

        if (teste == 2) //se a função retornar 2 houve erro de divisão por zero durante o calculo
        {
            printf ("Erro! Ocorreu uma divisao por zero! Talvez nao haja solucao!\n\nPressione [ENTER] para sair\n");
            fflush(stdin); op = getchar(); return 0;
        }

        //exibe o resultado na tela

        printf ("Resultados:\n\n");
        for (i=0; i<n; i++)
        {printf ("x%d = %f\n", i+1, x[i]);}

        printf ("\nDeseja salvar os resultados para um arquivo .csv?\nDigite [S] para sim, ou [N] para nao: ");
        fflush(stdin); op = getchar(); fflush(stdin);

        if (op == 's' || op == 'S') //salva os resultados em um arquivo .csv
        {

        printf ("\nDigite o nome do arquivo onde os resultados serao salvos:\n");
        scanf("%255[^\n]", nome_arq); fflush (stdin);

        strcat (nome_arq, ".csv"); //adiciona a extensao .csv no nome do arquivo
        troca_caractere (nome_arq, ' ', '_'); //substitui ' ' por '_' no nome do arquivo para evitar erros na abertura pela funcao system()

        //cria o arquivo de texto .csv para escrita
        if ((fp = fopen (nome_arq, "w")) == NULL)
        {printf ("\nErro na criacao do arquivo\n\nPressione [ENTER] para sair!\n"); op = getchar(); return 0;}

        //imprime um cabecalho no arquivo de texto .csv - sep=; indica que o separador de colunas eh um ;
        fprintf(fp, "sep=;\nMatriz LU - L abaixo da diagonal principal e U nas outras posicoes\n\n");
        for (i=0; i<(n-1); i++)
        {fprintf (fp, "x%d;", i+1);}
        fprintf (fp, "x%d;;Pb\n", n);

        //imprime a matriz no arquivo de texto .csv
        for (i=0; i<n; i++)
        {
            for (j=0; j<n; j++)
            {
                snprintf (buffer, 266, "%f", a[i][j]);
                troca_caractere (buffer, '.', ','); //troca o separador decimal de ponto para virgula, que eh o padrao do Brasil
                fprintf (fp, "%s;", buffer);
            }
            snprintf (buffer, 266, "%f", b[i]);
            troca_caractere (buffer, '.', ','); //troca o separador decimal de ponto para virgula, que eh o padrao do Brasil
            fprintf (fp, ";%s\n", buffer);
        }

        //imprime os resultados das variaveis
        for (i=0; i<n; i++)
        {
            snprintf (buffer, 266, "x%d =;%f", i+1, x[i]);
            troca_caractere (buffer, '.', ','); //troca o separador decimal de ponto para virgula, que eh o padrao do Brasil
            fprintf (fp, "\n%s", buffer);
        }
        
        fclose (fp);

        //abre o arquivo com o resultado para o usuario visualizar
        strcpy (buffer, "start ");
        strcat (buffer, nome_arq);
        system (buffer);

        } //fim do procedimento para salvar o resultado em um arquivo .csv

        printf ("\nDeseja reiniciar o programa? (digite [S] para sim, ou [N] para nao): ");
        fflush(stdin); op = getchar(); system ("cls");
    }
    while (op == 's' || op == 'S');
    return 0;
}
