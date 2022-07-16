#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
int main(){
	pid_t pid;
	int procnum, procs=4;
	for(procnum=0; procnum<procs-1;procnum++){
		pid=fork();
		if(pid==0) break;
	}
	printf("numero do processo: %d\n", procnum);
}