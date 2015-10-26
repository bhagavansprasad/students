#include <stdio.h>
#include <signal.h>
void abc();
main()
{
	printf("press del key.\n");
	signal(SIGINT,abc);
	for(;;);
}
void abc()
{
	printf("you are pressed the del key\n");
}
