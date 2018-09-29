#include <signal.h>
#include <stdio.h>

void abc();
main()
{
	printf("press <DEL> key.\n");
	signal(SIGINT ,abc);
	signal(SIGINT ,abc);
	signal(SIGINT ,abc);
	for(;;);
}

void abc()
{
	printf("you hava pressed the <DEL> key.\n");
}
