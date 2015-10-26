#include <stdio.h>
main()
{
	printf(" parent process ID is :%d\n",getpid());
	int pid=fork();
	if(pid==0)
		printf(" child process ID is :%d\n",getpid());

	int fork();
	if(pid==0)

		printf(" childs parent process ID is :%d\n",getppid());

}
