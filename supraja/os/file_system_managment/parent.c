#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 1;

	while(i <= 20)
	{
		int pid;

		pid = fork();
		if(pid != 0)
		{
			printf("-->parent : %d, child :%d\n", getppid(), getpid());
			sleep(100);
			exit(1);
		}
		printf("-->parent %d count :%d\n", getpid(), i);
		i++;
	}
	wait(1);
}	
