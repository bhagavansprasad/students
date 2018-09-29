#include <signal.h>
#include <stdio.h>
main()
{
	printf("press delete key to terminate\n");
	signal(SIGINT,SIG_DFL);
	for(;;);
}
