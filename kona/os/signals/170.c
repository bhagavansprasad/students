#include <stdio.h>
#include <signal.h>

void abc();
main()
{
	printf("press DEL key\n");
	signal(SIGINT,abc);
	signal(SIGINT,abc);
	signal(SIGINT,abc);
	for(;;);
}
void abc()
{
	printf("you have pressed the DEL key\n");
}
