#include <stdio.h>
#include <unistd.h>

main()
{
	printf("before the exec my ID is %d \n",getpid());
	printf("my parent process  ID is %d \n",getppid());
	
	printf("exec starts \n");
	execl("/home/bhagavan/students/viswa/os/pr51","pr51",(char *)0);
	printf("this will not print \n");
}
