#include <stdio.h>
#include <signal.h>
void abc();
main()
{
	printf("press <DEL>key.\n");
	signal(SIGINT,abc);
	for(;;);
}
void abc()
{
	printf("program terminate\n");
}
