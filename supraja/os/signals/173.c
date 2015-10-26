#include <stdio.h>
#include <signal.h>
void abc();
main()
{
	signal(SIGINT,abc);
	printf("press <DEL>key.\n");
	for(;;);
}
void abc()
{
	printf("you have pressed the <DEL>key.\n");
	signal(SIGINT,abc);
}
