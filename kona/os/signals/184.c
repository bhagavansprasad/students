#include <stdio.h>
#include <signal.h>
main()
{
	void abc();
	signal(SIGALRM,abc);
	alarm(30*60);
	pause();
}
void abc()
{
	printf("time to ring the sec.gen.my boy\n");
}
