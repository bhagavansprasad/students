#include <stdio.h>
#include <string.h>
#include <signal.h>

void sig_segv()
{
	printf("In sig_segv handler Pid :%d, %s\n", getpid(), __FUNCTION__);
}

void sig_int()
{
	printf("In sig_int handler Pid :%d, %s\n", getpid(), __FUNCTION__);
}

main()
{
	int a = 10;
	int b = 0;
	int c = 0;
	char *p = NULL;
	printf("cat /proc/%d/status\n", getpid());
	signal(SIGSEGV, sig_segv);
	signal(SIGINT,  sig_int);
	printf("After signal registering Pid :%d\n", getpid());

	for(;;)
		sleep(1);

	printf("After sleep Pid :%d\n", getpid());
	strcpy(p, "hello");
}
