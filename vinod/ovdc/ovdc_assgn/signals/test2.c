#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void handler();
main()
{
	printf("Use CTRL+C key for exiting\n");
	signal(SIGINT,handler);
	pause();
}

void handler()
{
	printf("\nYou have pressed the CTRL+C key\n");
}
