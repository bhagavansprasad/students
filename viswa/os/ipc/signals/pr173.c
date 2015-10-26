#include <signal.h>
#include <stdio.h>

void abc();
main()
{
	signal(SIGINT ,abc);
	printf("press <DEL> key.\n");
	for(;;);
}

void abc()
{
	printf("you hava pressed the <DEL> key.\n");
	signal(SIGINT ,abc);
}
