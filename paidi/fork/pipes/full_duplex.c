#include <stdio.h>
#include "string.h"

#define MACRO 126

char msg1[] = "Hai Father good morning , How are u , now i am in bangalore";
char msg2[] = "Hello son very good morning , me also fine, now I am in home";

void parent_process(int rfd, int wfd)
{
	char inbuf[MACRO];
	int retval = 0;
	while(1)
	{
	printf("\n");
	retval = read(rfd, inbuf, 25);
	inbuf[retval] = '\0';

	printf("parent reciver message from child is : %s\n ", inbuf);
	
	retval = write(wfd, msg2, strlen(msg2));
		
	sleep(2);
	}
}

void child_process(int wfd, int rfd)
{
	int retval = 0;
	char inbuf[MACRO];
	while(1)
	{
	retval = write(wfd, msg1, strlen(msg1));
	
	retval = read(rfd, inbuf, 25);
	inbuf[retval] = '\0';
	printf("child reciver message from parent is : %s\n ", inbuf);
	sleep(2);

	}
}

main()
{
	int pp[2],pc[2], pid;

	pipe(pp);
	pipe(pc);

	pid = fork();

	if(pid == 0)
	{
		close(pp[1],pc[0]);
		child_process(pc[1],pp[0]);
	}
	else
	{
		sleep(2);
		close(pc[1],pp[0]);
		parent_process(pc[0],pp[1]);
	}
}

