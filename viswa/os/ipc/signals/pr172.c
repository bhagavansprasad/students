#include <stdio.h>
#include <signal.h>

main()
{
	printf("press delete key (or) ctrl + \ keys.\n ");
	signal(SIGINT ,SIG_DFL);
	for(;;);
}
