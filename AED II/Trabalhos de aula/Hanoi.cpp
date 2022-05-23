/*Neste programa você vai trabalhar com o problema da Torre de Hanoi.
  Observe que o programa mostra a solução do problema, indicando a movimentação
  a ser feita. Você deve mudar a forma de mostrar o procedimento, indicando apenas,
  a cada passo, o total de pratos de cada vareta.*/
#include <iostream>
using namespace std;

int np, V[4];

void Hanoi(int n, int v1, int v2, int v3){
    if (n > 0) {
        Hanoi(n-1, v1, v3, v2);
        //cout <<"Move o topo da vareta " << v1 << " para a vareta " << v3 <<endl;
        cout<<" "<< V[1] <<" "<< V[2] <<" "<< V[3] <<endl;
        V[v1]--;
        V[v3]++; 
        Hanoi(n-1, v2, v1, v3);
    }
}
  
int main(){
    while(true){
	    cout << endl << "Num. de pratos, 0 para terminar: "; cin >> np;
	    V[1] = np;
	    if (np == 0) break;
        Hanoi(np, 1, 2, 3);
        cout<<" "<< V[1] <<" "<< V[2] <<" "<< V[3] <<endl;
        V[3] = 0;
        V[2] = 0;                
    }     
	return 0;	
}

