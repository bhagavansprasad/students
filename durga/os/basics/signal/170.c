#include<stdio.h>
#include <signal.h>
void abc();
main()
{
	printf("press the DEL key.\n");
	signal(SIGINT, abc);
	for( ; ;);
}

void abc(void)
{
	printf("you have pressed the DEL key.\n");
}
