#include <stdio.h>
#include <signal.h>

void sigkey();
main()
{
	signal( SIGQUIT , sigkey);
	signal( SIGQUIT , sigkey);
	for(;;);
}

void sigkey( signo )
int signo;
{
	printf("you have killed the process with signal no :->%d \n",signo);
}
