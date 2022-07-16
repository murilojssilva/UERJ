#include<stdio.h>
#include<unistd.h>
int main()
{
	int i = 1;
	int n = getc(stdin);
	pid_t proc[n];
	for (i=0;i<n;i++)		proc[i] = 0;
	for (i=0;i<n;i++)
	{
		proc[i]=fork();
		if (proc[i]<0)
		{
			perror("fork");
			fflush(stdout);
			return 1;
		}
		else if (proc[i] == 0)
		{
			printf("Pid do filho - %d.\n", getpid());
			fflush(stdout);
			break;

		}
		else
	}
	if (proc[n-1]>0)
	{
		for (i=0;i<n;i++) waitpid(proc[i]);
		fflush(stdout);
		printf("Termino dos filhos!\n");
	}
	return 0;
}