#include <signal.h>
#include <stdio.h>

void abc();
main()
{
	signal(SIGINT ,SIG_IGN);
	for(;;);
}


