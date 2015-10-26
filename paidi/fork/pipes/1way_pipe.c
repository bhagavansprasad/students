#include <stdio.h>
#include "string.h"

#define MACRO 1024

//char  msg1[MACRO] = "hai father ";
//char msg2[MACRO] = "Hello my son";

char  msg1[MACRO] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

char msg2[MACRO] = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
void parent_process(int rfd, int wfd)
{
	char inbuf[MACRO];
	int retval = 0;
	while(1)
	{
		retval = read(rfd, inbuf, 200);
		inbuf[retval] = '\0';
		printf(" I am Parent msg :%s\n", inbuf);

		retval = write(wfd, msg2,strlen(msg2));
		sleep(2);
	}
}

void child_process(int wfd, int rfd)
{
	char inbuf[MACRO];
	int retval = 0;
	while(1)
	{
		retval = write(wfd, msg1, strlen(msg1));

		retval = read(rfd, inbuf, 200);
		inbuf[retval] = '\0';

		printf("The Child msg is :  %s\n", inbuf);

		sleep(5);
	}
}

main()
{
	int p[2], pid;

	pipe(p);

	pid = fork();

	if(pid == 0)
	{
		child_process(p[1],p[0]);
		sleep(5);
	}
	else
	{
		//sleep(2);
		parent_process(p[0],p[1]);
	}
}

