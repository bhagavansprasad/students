#include<stdio.h>
#include <signal.h>

void abc(void)
{
	printf("you have pressed the DEL key.\n");
}

main()
{
	printf("press the DEL key.\n");
	signal(SIGINT, abc);
	for( ; ;);
}

