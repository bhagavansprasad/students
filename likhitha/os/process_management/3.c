#include <stdio.h>

main()
{
	printf("--->process id       : %u\n", getpid());
	printf("-->parent process id : %u\n", getppid());
	printf("-->user id           : %u\n", getuid()); 
	printf("-->Effective user id : %u\n", geteuid()); 
	printf("-->group id          : %u\n", getgid()); 
	printf("-->Effective group id : %u\n", getegid()); 
}
