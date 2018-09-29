#include "stdio.h"
void main()
{
	fork();
	fork();
	fork();
	
	printf("pid: %d\n", getpid());
	printf("--> ppid: %d\n", getppid());
	printf("hello \n");
}
