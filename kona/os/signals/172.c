#include <stdio.h>
#include <signal.h>
main()
{
	printf("press the delete to terminate\n");
	signal(SIGINT,SIG_DFL);
	for(;;);
}
