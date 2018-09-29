#include <stdio.h>
#include <signal.h>
#define ALARM_TIME 1
void handler(int signo);
main()
{
	
	signal(SIGALRM,handler);
	alarm(ALARM_TIME*60);
	pause();
}

void handler(int signo)
{
	printf("Received alarm handler\n");
	printf("Received signo -> %d\n",signo);
}
