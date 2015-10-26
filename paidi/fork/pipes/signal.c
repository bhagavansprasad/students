#include <stdio.h>
#include <signal.h>
void abc();
main()
{ 
	printf("press ctrl + c\n");
	signal(SIGINT,abc);
	for(;;);
}
void abc()
{
	int i;
	printf("u have pressed ctrl + c\n");
	for(i=0;i<10;i++)
	{
		printf("%d\n",i);
	}
}
