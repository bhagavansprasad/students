#include <stdio.h>
#define N 3
int main()
{
	int i=0;
	int p;
	for(i=0;i<N;i++)
	{
		p=fork();
		if(p == 0)
		{
			printf("child pid -> %d   parent pid -> %d\n", getpid(), getppid());
			continue;
		}
		else 
			sleep(10000000);
	}
	return 0;
}
