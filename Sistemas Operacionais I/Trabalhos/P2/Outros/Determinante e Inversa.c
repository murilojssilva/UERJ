//Calculo do determinante e da inversa de uma matriz quadrada qualquer
//Luiz Vinicius Soglia - lvmsoglia@hotmail.com

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


//==========================================================================================================
        
// Função para calcular o Determinante e a Inversa de uma matriz
//n é a ordem da matriz que se deseja calcular o determinante e a inversa
//mA é a matriz que se deseja calcular
//mI é uma matriz que guardará a matriz inversa ao final da execução da função, caso exista inversa (det diferente de zero)

float det_inversa (int n, float mA[][n], float mI[][n])
{  
        int i, j, k, posl, erro;
        float det, aux, pivo, m;
        
        //Constroi a matriz identidade [mI] para ser usada no calculo da inversa
        for (i=0; i<n; i++)
        {
            for (j=0; j<n; j++)
            {
                if (i==j)
                {mI[i][j] = 1.0;} //diagonal principal
                else
                {mI[i][j] = 0.0;}
            }
        }
        
        det=1.0; //det inicialmente guarda as trocas de sinal do determinante, caso haja mudanças de linhas no pivoteamento parcial
        erro = 0; //A variavel erro se tornara 1 caso haja erros de divisao por zero
        
        //pivoteamento parcial e Metodo da eliminacao de Gauss (Triangularizacao superior)
        for (k=0; k<(n-1); k++)
        {    
            
            pivo=fabs(mA[k][k]); //pivo inicial
            posl=k; //posicao da linha do pivo
            for (i=k+1; i<n; i++)
            {
                if (fabs(mA[i][k])>pivo)
                {
                    pivo=fabs(mA[i][k]); //passa a ser o novo pivo
                    posl=i; //guardam a posicao (linha e coluna) do maior pivo
                }
	        }
	    
            if (posl!=k) //caso o pivo nao esteja na linha k, troca linha k pela linha posl
            {
                for (j=k; j<n; j++)
                {
	                aux=mA[k][j];
	                mA[k][j]=mA[posl][j];
	                mA[posl][j]=aux;
                }
                //tambem faz as mesmas operacoes na matriz identidade
                for (j=0; j<n; j++)
                {
                   aux=mI[k][j];
	               mI[k][j]=mI[posl][j];
	               mI[posl][j]=aux;
                }
                if ((posl-k)%2 != 0) //se for um numero impar de diferença entre as linhas
                {det = det*(-1);} //com a troca de linhas, o determinante muda de sinal, det guarda o sinal do determinante
            }
	   
	       //Metodo da eliminacao de Gauss (Triangularizacao superior)
	       if (mA[k][k] != 0) //Evita erros de divisao por zero
	       {
                for (i=k+1; i<n; i++)
                {
                    m = mA[i][k]/mA[k][k]; //calcula o multiplicador
                    mA[i][k] = 0.0; //agora assume zero para o valor a ser zerado, afim de poupar tempo
                    for (j=k+1; j<n; j++) //comeca do elemento apos o valor a ser zerado
                    {
                        mA[i][j] = mA[i][j] - (m*mA[k][j]);
                    }
                    //tambem faz as mesmas operacoes na matriz identidade
                    for (j=0; j<n; j++)
                    {
                        mI[i][j] = mI[i][j] - (m*mI[k][j]);
                    }
                }
            }
            else
            {erro = 1; break;} //Houve erro de divisão por zero - todos os pivôs são zero
        
        } //fim do pivoteamento parcial e Metodo da eliminacao de Gauss (Triangularizacao superior)

        if (erro == 1) //Houve erro de divisao por zero - um dos pivos é igual a zero e com isso det sera zero
        {return 0.0;}
        
        //Calcula o det. Como a matriz agora eh triangular superior, o det sera o produto dos elementos da diagonal principal
        for (k=0; k<n; k++)
        {det = det * mA[k][k];}
        
        if (det == 0.0)
        {return 0.0;}
          
        //calcula a inversa - faz uma triangularizacao inferior para tornar a matriz [mA] uma matriz diagonal e depois identidade
        //mas esses passos só serão aplicados em [mI], que guardara a matriz inversa ao final dos passos

        for (k=n-1; k>0; k--)
        {
            if (mA[k][k] != 0) //Evita erros de divisao por zero
	        {
                for (i=k-1; i>=0; i--)
                {
                    m = mA[i][k]/mA[k][k]; //calcula o multiplicador
                    for (j=0; j<n; j++)
                    {
                        mI[i][j] = mI[i][j] - (m*mI[k][j]);
                    }
                }           
            }
            else
            {erro = 1; break;} //Houve erro de divisão por zero - um elemento da diagonal principal eh igual a zero
        }
        if (erro == 1)
        {return 0.0;}
            
        //finaliza dividindo a matriz [pelos elementos da diagonal principal, ultimo passo para transforma-la em matriz inversa
        for (i=0; i<n; i++)
        {
            for (j=0; j<n; j++)
            {
                mI[i][j] = mI[i][j]/mA[i][i];
            }
        }
        
        return det;
}
//==========================================================================================================

//Função principal

int main()
{
    int n, i, j, carregamento;
    char op, nome_arq[260];
    float det;
    FILE *fp;

    do
    {
        printf ("Calculo do Determinate e da Inversa de uma matriz quadrada [A] qualquer\n\n"); 
        do
        {
            printf ("Digite a ordem da matriz quadrada (n), no maximo n=100: ");
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
        float mA[n][n], mI[n][n]; //cria a matriz [mA] e uma matriz que guardara a sua inversa [mI]
        
        //faz o carregamento da matriz [mA] de acordo com a opcao escolhida
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
                    scanf ("%f", &mA[i][j]);
                }
                printf ("\nOs valores digitados estao corretos? (digite [S] para sim, ou [N] para nao): ");
                fflush(stdin); op = getchar();
            }
            while (op != 's' && op != 'S');
        }
        break;
        
        case 2: //carrega do arquivo
        do
        {
            printf ("\nDigite o caminho (com a extensao) do arquivo de texto com os dados:\n");
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
        //inicializa e lê os coeficientes da matriz mA
        for (i=0; i<n; i++)
        {
            for (j=0; j<n; j++)
            {             
                mA[i][j]=0.0;
                fscanf (fp, "%f", &mA[i][j]);
            }
        }
        fclose(fp);
        break;
        
        default: 
        printf ("\nOcorreu um erro! Pressione [ENTER] para sair\n"); fflush(stdin); op = getchar(); return 0;
        
        } //fim do carregamento da matriz
        
        system ("cls");
        printf ("Dados carregados com sucesso!\nPressione [ENTER] para continuar e calcular o Determinante e a Inversa\n");
        fflush(stdin); op = getchar(); system ("cls");
        
        //Chama a funcao que calcula o determinante e a inversa da matriz    
        det = det_inversa (n, mA, mI);
        
        if (det == 0.0) //se det igual a zero a matriz nao possui inversa
        {printf ("Determinante (det A) = 0\nA matriz A nao possui inversa!\n\nPressione [ENTER] para sair\n"); op = getchar(); return 0;}
        
        printf ("Determinante (det A) = %f\n\nDeseja visualizar a Inversa da matriz? Digite [S] para sim, ou [N] para nao: ", det);
        fflush(stdin); op = getchar(); fflush(stdin);
        if (op == 's' || op == 'S')
        {
            //cria o arquivo de texto .txt para escrita
            if ((fp = fopen ("MATRIZ_INVERSA.txt", "w")) == NULL)
            {printf ("\nErro ao salvar a matriz inversa em um arquivo!\n\nPressione [ENTER] para sair!\n"); op = getchar(); return 0;}
     
            //imprime a matriz inversa no arquivo de texto .txt
            for (i=0; i<n; i++)
            {
                for (j=0; j<n; j++)
                {
                    fprintf (fp, "%f ", mI[i][j]);
                }
                fprintf (fp, "\n");
            }

            fclose (fp);
        
            //abre o arquivo com o resultado para o usuario visualizar
            system ("start MATRIZ_INVERSA.txt");
        }
        
        printf ("\nDeseja reiniciar o programa? (digite [S] para sim, ou [N] para nao): ");
        fflush(stdin); op = getchar(); system ("cls");
    }
    while (op == 's' || op == 'S');
    return 0;    
}
