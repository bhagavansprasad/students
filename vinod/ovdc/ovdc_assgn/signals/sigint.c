#include <stdio.h>
#include <signal.h>

void catch(int signo);

main()
{
	int i=0;
	printf("Use CTRL+c key for catching\n");
	signal(SIGINT,catch);
	for(;i<5;i++)
		pause();
}

void catch(int signo)
{
	printf("\nThe signo -> %d\n", signo);
	printf("I caught the SIGINT signal\n");
}
