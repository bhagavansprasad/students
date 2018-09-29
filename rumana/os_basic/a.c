#include <stdio.h>
int main()
{
	int pid,i;
	for(i=0;i<3;i++)
	{
		pid==fork();
		if(pid > 0)
		{
			printf("%d %d\n",getpid(),getppid());
		}
		else
		{
			sleep(5);
		}
	}
}	
