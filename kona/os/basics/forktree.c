#include <stdio.h>
#include <stdlib.h>
main()
{
	fork();
	fork();
	fork();
	printf("the process ID is:%d%d\n",getpid(),getppid());
	//sleep(10);
}
