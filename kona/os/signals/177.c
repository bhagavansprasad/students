#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void sigkey();
main()
{
	int i=0,j=50;
	signal(SIGILL,sigkey);
	j=j/i;
}
void sigkey(signo)
int signo;
{
	printf("the process recevied a signal %d\n",signo);
	exit(0);
}
