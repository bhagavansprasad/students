#include <stdio.h>

//Every process has a real user ID (the UID), an effective user ID (the EUID)
//A real user group ID (the GID), and an effective user group ID (the EGID). The user group ID is distinct from the process group ID.

main()
{
	printf("--->process id       : %u\n", getpid());
	printf("-->parent process id : %u\n", getppid());
	printf("-->user id           : %u\n", getuid()); 
	printf("-->Effective user id : %u\n", geteuid()); 
}
