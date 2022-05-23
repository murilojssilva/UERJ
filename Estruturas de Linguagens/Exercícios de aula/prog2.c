#include <stdio.h>
struct PontoPlano{
	int x,y;
};
struct PontoEspaco{
	int x,y,z;
};
struct Ponto{
	char EstaNoPlano;
	union{
		struct PontoPlano r2;
		struct PontoEspaco r3;
	}valor;
};
struct Ponto a[10],b[10],c[10],p[10];
void operacao
void main(void){
	if  (p[10].EstaNoPlano);
		operacao_1(p[10])
	else
		operacao_2(p[10])
}

