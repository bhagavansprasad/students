#include <stdio.h>
main()
{
	int pid;
	pid=fork();
	if(pid>0)
//	fork();
	printf("the parent process PID is %d\n",pid);
}
