#include<stdio.h>
#include<stdlib.h>

int ehPrimo(long num){
	long i;
	if(num<=1)return 0;
	for(i=2;i<num;i++){
		if(num%i==0)return 0;
	}
	return 1;
}

int main(int argc,char* argv[]){
	int i, num, cont=0;
	num=atoi(argv[1]);
	for(i=0;i<num;i++){
		if(ehPrimo(i)) 
			cont++;
	}
	printf("Total de primos: %d",cont);
	return 0;
}