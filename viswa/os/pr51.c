#include <stdio.h>

main()
{
	printf("After the exec my process id is %d \n ",getpid());
	printf("my parent process id is %d \n ",getppid());
	
	printf("exec ends \n");
}
