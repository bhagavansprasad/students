#include <stdio.h>

main()
{
	printf("I am forking a child process\n");
	int pid=fork();
	if(pid == 0)
	{
		printf("child process\n");
		printf("--->process id       : %u\n", getpid());
		printf("-->parent process id : %u\n", getppid());
		printf("-->user id           : %u\n", getuid()); 
		printf("-->Effective user id : %u\n", geteuid()); 
		printf("-->group id          : %u\n", getgid()); 
		printf("-->Effective group id : %u\n", getegid()); 
	}
	else
	{
		printf("parent process\n");
		printf("--->process id       : %u\n", getpid());
		printf("-->parent process id : %u\n", getppid());
		printf("-->user id           : %u\n", getuid()); 
		printf("-->Effective user id : %u\n", geteuid()); 
		printf("-->group id          : %u\n", getgid()); 
		printf("-->Effective group id : %u\n", getegid()); 
	}

}
