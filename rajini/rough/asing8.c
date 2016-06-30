#include <stdio.h>
main()
{
	int pid=fork();
	//if(pid == 0)
	//	printf("child process\n");
	if(pid<0)
		printf("fork is failed\n");
	else
		printf("fork is success\n");
}
