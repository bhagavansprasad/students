#include <stdio.h>
#include "string.h"

#define MACRO 126

char  msg[] = "hai_TO_auranet";

void parent_process(int rfd)
{
	char inbuf[MACRO];
	int retval = 0;
	while(1)
	{
	printf("\n\n");
	printf("-->I am Parent my pid :%d\n",getpid());
	printf("-->I am Parent closing write fd\n");
	printf("-->I am Parent reading data from client over pipe\n");

	retval = read(rfd, inbuf, MACRO);

	printf("-->I am Parent read retval :%d\n", retval);
	inbuf[retval] = '\0';
	printf("-->I am Parent msg :%s\n", inbuf);
	printf("-->I am Parent exiting :%d\n", getpid());
	sleep(5);
	printf("\n\n");
	}
}

void child_process(int wfd)
{
	int retval = 0;
	while(1)
	{
	printf("\n\n");
	printf("-->I am Child my pid  :%d\n", getpid());
	printf("-->I am Child closing read fd\n");


	printf("-->I am Child Writing  '%s' to parent over pipe\n", msg);

	retval = write(wfd, msg, strlen(msg));
	printf("-->I am Child write retval :%d\n", retval);

	printf("-->I am Child exiting :%d\n",getpid());
	sleep(5);
	printf("\n\n");
	}
}

main()
{
	int p[2], pid;

	pipe(p);

	pid = fork();

	if(pid == 0)
	{
		close(p[0]);
		child_process(p[1]);
	}
	else
	{
		sleep(2);
		close(p[1]);
		parent_process(p[0]);
	}
}

