#include <stdio.h>
#include <signal.h>
void abc();
main()
{
	signal(SIGHUP,SIG_IGN);
	printf("press del key");
	for(;;);
}

