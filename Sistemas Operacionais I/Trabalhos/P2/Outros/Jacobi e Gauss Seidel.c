//Resolucao de sistemas lineares utilizando os metodos iterativos de Jacobi e Gauss Seidel
//Luiz Vinicius Soglia - lvmsoglia@hotmail.com

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


//==========================================================================================================

//funcao que implementa a resolução de sistemas lineares pelos metodos iterativos de Jacobi e Gauss Seidel.

//n: é a ordem do sistema.
//metodo: guarda o método  a ser utilizado para a resulução: 1 = jacobi, 2 = gauss seidel.
//matriz a[][]: é a matriz dos coeficientes.
//matriz b[]: é a matriz dos termos independentes.
//matriz x[]: guarda os valores das variaveis após a resolução.
//e: é o valor de tolerancia de erro aceitavel no resultado, para ser utilizado como criterio de parada.
//k_max: é o numero de iterações maxima permitida. k_max=0 significa ilimitado (mas na realidade faz 100000 iterações, por segurança).

//O criterio de parada utilizado é o erro relativo: dr = max|xi(k) - xi(k-1)| / max|xi(k)|

//retorna 0 caso haja sucesso, 1 para erros de entrada de argumentos invalidos, 2 para erros de divisão por zero.

int iterativos_jacobi_gauss_seidel (int n, int metodo, float a[][n], float b[], float x[], float e, int k_max)
{

    int k, i, j;
    float s, dr, x_max;
    float x_aux[n]; //variavel auxiliar que guarda os valores das variaveis xi's da iteracao anterior
    
    if (n < 2 || e < 0.0 || k_max < 0) //testa se existe argumentos invalidos
    {return 1;}
    
    if (k_max == 0) //simula um numero de iteracoes "ilimitado" (maximo de 100000 iteracoes)
    {k_max = 100000;}

    switch (metodo) //aplica o metodo iterativo escolhido
    {
        
        //Jacobi ===============================================================
        case 1:
        {
            for (k=1; k<=k_max; k++)
            {
                for (i=0; i<n; i++)
                {x_aux[i] = x[i];} //guarda os valores de x da iteracao anterior
                
                for (i=0; i<n; i++)
                {  
                    if (a[i][i] != 0.0) //Evita erros de divisao por zero
	                {
                        s = a[i][i]*x_aux[i]; //começa com o termo que nao deveria entrar nas subtrações...para anular sua participação
                        for (j=0; j<n; j++)
                        {s = s - a[i][j]*x_aux[j];}
                        s = b[i] + s;
                        x[i] = s / a[i][i];
                    }
                    else
                    {return 2;} //Houve erro de divisão por zero
                }
                
                //tolerancia de erro - busca o valor maximo entre |xi(k) - xi(k-1)|/|xi(k)|, testando se é menor do que erro aceitavel
                dr = fabs(x[0] - x_aux[0]);
                x_max = fabs(x[0]);
                for (i=1; i<n; i++)
                {
                    if (fabs(x[i] - x_aux[i]) > dr)
                    {dr = fabs(x[i] - x_aux[i]);}
                    
                    if (fabs(x[i]) > x_max)
                    {x_max = fabs(x[i]);}
                }
                dr = dr / x_max;
                if (dr < e) //se dr (erro relativo) for menor do que a tolerancia, a solução é aceitavel e termina a execucao do metodo
                {k++; break;}
            }
        }
        break;
        
        //Gauss Seidel =========================================================
        case 2:
        {
            for (k=1; k<=k_max; k++)
            {
                for (i=0; i<n; i++)
                {x_aux[i] = x[i];} //guarda os valores de x da iteracao anterior
                
                for (i=0; i<n; i++)
                {  
                    if (a[i][i] != 0.0) //Evita erros de divisao por zero
	                {
                        s = a[i][i]*x[i]; //começa com o termo que nao deveria entrar nas subtrações...para anular sua participação
                        for (j=0; j<n; j++)
                        {s = s - a[i][j]*x[j];}
                        s = b[i] + s;
                        x[i] = s / a[i][i];
                    }
                    else
                    {return 2;} //Houve erro de divisão por zero
                }
                
                //tolerancia de erro - busca o valor maximo entre |xi(k) - xi(k-1)|/|xi(k)|, testando se é menor do que erro aceitavel
                dr = fabs(x[0] - x_aux[0]);
                x_max = fabs(x[0]);
                for (i=1; i<n; i++)
                {
                    if (fabs(x[i] - x_aux[i]) > dr)
                    {dr = fabs(x[i] - x_aux[i]);}
                    
                    if (fabs(x[i]) > x_max)
                    {x_max = fabs(x[i]);}
                }
                dr = dr / x_max;
                if (dr < e) //se dr (erro relativo) for menor do que a tolerancia, a solução é aceitavel e termina a execucao do metodo
                {k++; break;}
            }
        }
        break;

        //Caso não exista a opção de método passada para a função, implica em erro. Retorna 1, indicando esse erro.
        default:
        return 1;

    } //fim do switch-case com os metodos iterativos
   
   printf ("Foram realizadas %d iteracoes\nErro relativo = max |xi(k) - xi(k-1)| / max |xi(k)| = %f\n\n", k-1, dr);
   return 0;
}


//==========================================================================================================

//funcao que implementa o criterio de convergencia das linhas.
//a[][] é a matriz dos coeficientes.
//retorna o valor de alfa. Se alfa < 1 o método de Jacobi ou Gauss Seidel gera uma sequencia convergente
//retona -1 caso haja elementos iguais a zero na diagonal principal, o que inviabiliza os metodos iterativos de Jacobi e Gauss Seidel

float criterio_linhas (int n, float a[][n])
{
    float alfa, aux;
    int i, j;
    
    alfa=0.0;
    for (i=0; i<n; i++)
    {
        if (a[i][i] != 0.0) //evita divisões por zero
        {
            aux = - fabs(a[i][i]); //inicia alfa com o negativo do termo que nao deve entrar no somatorio, para anular sua participacao
            for (j=0; j<n; j++)
            {
                aux = aux + fabs(a[i][j]);
            }
            aux = aux/fabs(a[i][i]);
            if (aux > alfa)
            {alfa = aux;}
        }
        else
        {return -1;} //Se houver zeros na diagonal principal retorna -1 indicando esse erro
    }
    return alfa;        
}


//==========================================================================================================

//funcao que implementa o criterio de convergencia de Sassenfeld (somente para o metodo de Gauss Seidel).
//a[][] é a matriz dos coeficientes.
//retorna o valor de beta. Se beta < 1 o método de Gauss Seidel gera uma sequencia convergente
//retona -1 caso haja elementos iguais a zero na diagonal principal, o que inviabiliza o metodo iterativo de Gauss Seidel

float criterio_sassenfeld (int n, float a[][n])
{
    float beta[n], beta_max, aux;
    int i, j;
    
    beta_max=0;
    for (i=0; i<n; i++)
    {beta[i] = 1.0;} //inicializa todos os betas com 1, elemento neutro da multiplicacao
    
    for (i=0; i<n; i++)
    {
        if (a[i][i] != 0.0) //evita divisões por zero
        {
            aux = - fabs(a[i][i]); //inicia alfa com o negativo do termo que nao deve entrar no somatorio, para anular sua participacao
            for (j=0; j<n; j++)
            {
                aux = aux + fabs(a[i][j])*beta[j];
            }
            beta[i] = aux/fabs(a[i][i]);
            if (beta[i] > beta_max)
            {beta_max = beta[i];}
        }
        else
        {return -1;} //Se houver zeros na diagonal principal retorna -1 indicando esse erro
    }
    return beta_max;        
}


//==========================================================================================================

//Função principal

int main()
{
    int n, i, j, k_max, metodo, carregamento, teste;
    float e, alfa, beta;
    char op, nome_arq[260];
    FILE *fp;

    do
    {
        printf ("Resolucao de sistemas lineares por metodos iterativos de Jacobi e Gauss Seidel\n\n");
        do
        {
            printf ("Digite a ordem do sistema (n), no maximo n=100: ");
            fflush(stdin); scanf ("%d",&n);
        }
        while (n < 2 || n > 100);


        printf ("\nDigite a opcao do metodo iterativo:\n\n[1] Jacobi\n[2] Gauss Seidel\n\n");
        do
        {
            printf ("Opcao: ");
            fflush(stdin); scanf ("%d",&metodo);
        }
        while (metodo < 1 || metodo > 2);
        
        do
        {
            printf ("\nDigite o numero maximo de iteracoes permitidas (digite 0 para ilimitado): ");
            fflush(stdin); scanf ("%d",&k_max);
        }
        while (k_max < 0);
        
        do
        {
            printf ("\nDigite a tolerancia de erro aceitavel: ");
            fflush(stdin); scanf ("%f",&e);
        }
        while (e < 0.0);

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

        //digita a matriz
        case 1:
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
        
        do
        {
            system ("cls");
            printf ("Digite a soluca inicial:\n\n");
            for (i=0; i<n; i++)
            {
                printf ("x[%d] = ", i+1);
                scanf ("%f", &x[i]);
            }
            printf ("\nOs valores digitados estao corretos? (digite [S] para sim, ou [N] para nao): ");
            fflush(stdin); op = getchar();
        }
        while (op != 's' && op != 'S');
        break;
        
        //carrega do arquivo
        case 2:
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
        //inicializa e lê os coeficientes das matrizes A e B e a solução inicial
        for (i=0; i<n; i++)
        {
            for (j=0; j<n; j++)
            {
                a[i][j]=0.0;
                fscanf (fp, "%f", &a[i][j]); //matriz A
            }
            b[i]=0.0;
            fscanf (fp, "%f", &b[i]); //matriz B
        }
        for (i=0; i<n; i++)
        {fscanf (fp, "%f", &x[i]);} //solucao inicial
        fclose(fp);
        break;

        default:
        printf ("\nOcorreu um erro no carregamento do sistema! Pressione [ENTER] para sair\n"); fflush(stdin); op = getchar(); return 0;

        } //fim do carregamento da matriz
        
        //criterio de convergencia das linhas
        system ("cls");
        printf ("Deseja verificar a convergencia pelo criterio das linhas?\nDigite [S] para sim e [N] para nao: ");
        fflush(stdin); op = getchar();
        if (op == 's' || op == 'S')
        {
            alfa = criterio_linhas (n, a);
            if (alfa >= 0)
            {
                if (alfa < 1)
                {printf ("\nalfa = %f. alfa < 1, convergencia garantida!\n", alfa);}
                else
                {printf ("\nalfa = %f. alfa >= 1, nao existe convergencia garantida!\n", alfa);}
            }
            else
            {
                 printf ("\nHa elementos iguais a zero na diagonal principal, isso inviabiliza\nos metodos iterativos!");
                 printf (" Tente reagrupar as equacoes para que nao existam zeros\nna diagonal principal!\n\nPressione [ENTER] para sair\n");
                 fflush(stdin); op = getchar(); return 0;
            }
        }
        
        //criterio de convergencia de Sassenfeld (somente para o metodo de Gauss Seidel)
        if (metodo == 2) //metodo de Gauss Seidel
        {
        printf ("\nDeseja verificar a convergencia pelo criterio de Sassenfeld?\nDigite [S] para sim e [N] para nao: ");
        fflush(stdin); op = getchar();
        if (op == 's' || op == 'S')
        {
            beta = criterio_sassenfeld (n, a);
            if (beta >= 0)
            {
                if (beta < 1)
                {printf ("\nbeta = %f. beta < 1, convergencia garantida!\n", beta);}
                else
                {printf ("\nbeta = %f. beta >= 1, nao existe convergencia garantida!\n", beta);}
            }
            else
            {
                 printf ("\nHa elementos iguais a zero na diagonal principal, isso inviabiliza o metodo\nde Gauss Seidel!");
                 printf (" Tente reagrupar as equacoes para que nao existam\nzeros na diagonal principal!\n\nPressione [ENTER] para sair\n");
                 fflush(stdin); op = getchar(); return 0;
            }
        }
        }

        printf ("\nDados carregados! Pressione [ENTER] para continuar e resolver o sistema linear\n");
        fflush(stdin); op = getchar(); system ("cls");

        //Chama a função que aplica o metodo iterativo - retorna zero para teste caso haja sucesso
        teste = iterativos_jacobi_gauss_seidel (n, metodo, a, b, x, e, k_max);

        if (teste == 1) //se a função retornar 1, argumentos invalidos foram passados para a função
        {
            printf ("Erro! Argumentos invalidos foram digitados!\n\nPressione [ENTER] para sair\n");
            fflush(stdin); op = getchar(); return 0;
        }

        if (teste == 2) //se a função retornar 2 houve erro de divisão por zero durante o calculo
        {
            printf ("Ocorreu erro de divisao por zero!\n");
            printf ("Tente reagrupar as equacoes para que nao existam zeros na diagonal principal!\n\nPressione [ENTER] para sair\n");
            fflush(stdin); op = getchar(); return 0;
        }

        //exibe o resultado na tela
        printf ("Resultados:\n\n");
        for (i=0; i<n; i++)
        {printf ("x%d = %f\n", i+1, x[i]);}

        printf ("\nDeseja reiniciar o programa? (digite [S] para sim, ou [N] para nao): ");
        fflush(stdin); op = getchar(); system ("cls");
    }
    while (op == 's' || op == 'S');
    return 0;
}
