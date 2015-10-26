#include <stdio.h>
main()
{
	printf("I am forking a child process\n");
	fork();
	fork();
	fork();
	printf("Process pid -> %d Parent process pid -> %d\n", getpid(), getppid());
	sleep(10);
}
