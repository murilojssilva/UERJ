/*Neste programa voc? vai trabalhar com o problema Torneio, quando o n?mero de
  participantes ? uma pot?ncia de 2. Voc? vai implementar a Vers?o 2, estudada
  em sala. Voc? deve apenas programar o procedimento TorneioV2, cujo algoritmo
  ? mostrado, e rodar para k variando de 1 a 10.
  O programa deve mostrar a matriz de torneio para n = 2^k. */
#include <stdio.h>
using namespace std;
int i,j,k,n, T[1025][1025];

int TorneioV2(int m){
    int i,j,p;
/*
Torneio (m);
	Se (m = 1) Ent?o T[1,1] <- 1
	Sen?o
		p <- m/2;   Torneio(p);
		Para i de 1 a p:
			Para j de 1 a p:
				T[i+p, j]  <- T[i, j] + p;
				T[i, j+p]  <- p+1+(i+j-2) mod p;
				T[p+1+(i+j-2)mod p, j+p] <- i;
			Fp;
		Fp;
Fim; */
     
     if (m == 1)
           T[1][1] = 1;
     else
     {
         p = m/2;
         TorneioV2(p);
         for (i=1; i<=p; i++)
         {
             for (j=1; j<=p; j++)
             {
                 T[i+p][j] = T[i][j] + p;
                 T[i][j+p] = T[i+p][j];
                 T[i+p][j+p] = T[i][j];
             }
         }
     }     
}      
int main(){
    while(true){
        cout<<endl<<"Informe k, 0 para terminar:";  cin >> k;
        if (k == 0) break;
		n = 1; for (i=1; i<=k; i++) n = 2*n; 
        TorneioV2(n);
        for (i=1; i<=n; i++){
             for (j=1; j<=n; j++) cout<< " "<< T[i][j];  cout<<endl;
        }     
	}
	return 0;	
}
