#include <stdio.h>
struct Ponto{
	int x,y;
};

void main(void){
	struct Ponto p0 = {1,1},p1;
	p1.x = -1;
	p1.y = 1;
	if (p0.x == p1.x && p0.y == p1.y)
		printf("p0 e p1 sao o mesmo ponto\n");
	//else
	//	printf("p0 e p1 sao pontos diferentes\n");
}

