#include<stdio.h>

int main()
{
	printf("I am forking a child process \n");
	fork();
	printf("Who am i? ? Child or parent ? My ID process : %u \n",getpid());
	return 0;
}
