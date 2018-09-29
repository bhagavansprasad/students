#include <stdio.h>
main()
{ 
	printf( " I am forking a child process \n ");
	int pid = fork ();
	
	if(pid == 0)

		printf("-->child process id : %u\n", getpid());

	else
		printf("-->parent process id : %d\n", getppid());

}
