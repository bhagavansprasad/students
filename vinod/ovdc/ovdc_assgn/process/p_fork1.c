#include <stdio.h>
main()
{
	printf("I am forking a child process\n");
	fork();
	printf("who am i ? child or parent ? My Process ID : %u\n", getpid());
}
