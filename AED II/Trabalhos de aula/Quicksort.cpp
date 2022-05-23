/*Neste programa você vai trabalhar com o Quicksort, para vetores de até 1000000
  de elementos. Você deve apenas programar o procedimento Quicksort, cujo algori-
  tmo é dado. Depois vai rodar o programa para n = 1000, 10000, 100000 1 1000000
  e relatar, de forma simplificada, os tempos obtidos.
  Observe que o programa já prepara dois grupos de dados. O primeiro é com éntra-
  da aleatória e o segundo, com entrada inversamente ordenada. */
#include <time.h>
#include <iostream>
using namespace std;

int i, n, V[1000001];

int Quicksort(int e, int d){
    int i,j,k,t;
/*
Quicksort (e, d);
	Se (d > e) Então
		i <- e;  j <- d;  t <- V[(i+j)/2];
		Enquanto (i<=j):
			Enquanto(V[i] < t) i++:
            Enquanto(V[j] > t) j--;
            Se (i <= j) Então
				k <- V[i];  V[i] <- V[j]; V[j] <- k; i++ j--;
		    Fs;	
        Fe;    	
  	    Quicksort(e,j);
        Quicksort(i,d);
    Fs;        
Fim; */
     if (d > e){
        i = e;  
        j = d;  
        t = V[(i+j)/2];
        while (i<=j){
              while(V[i] < t) 
                         i++;
              while(V[j] > t) 
                         j--;
              if (i <= j){
                 k = V[i];
                 V[i] = V[j];
                 V[j] = k;
                 i++;
                 j--;
              }
        } 	
        Quicksort(e,j);
        Quicksort(i,d);   
     }
}

int min(int a, int b){ if (a<b) return a; else return b;}    
int main(){
    srand (time(NULL));
    while(true){
	    cout<< endl <<"Informe n, o para terminar: ";   cin >> n;
	    if (n == 0) break;
		for (i=1; i<=n; i++) V[i] = rand()*rand()%1000000;
        Quicksort(1,n);
        cout<<"Teste 1: entrada aleatoria - primeiros 40 elementos: ";
        for (i=1; i<=min(n,40); i++) cout <<" "<<V[i]; cout<<endl<<endl;
		for (i=1; i<=n; i++) V[i] = 1000001-i;
        Quicksort(1,n);
        cout<<"Teste 2: entrada inv, ordenada - primeiros 40 elementos: ";
        for (i=1; i<=min(n,40); i++) cout <<" "<<V[i]; cout<<endl<<endl;
   
    }     
	return 0;	
}

