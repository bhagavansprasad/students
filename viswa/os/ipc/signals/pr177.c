#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigkey();
main()
{
	int i = 0 ,j = 50;
	signal(SIGILL , sigkey);
	j = j/i;
}

void sigkey(signo)
int signo;
{
	printf("the process received a signal ->%d\n", signo);
	exit(0);
}
