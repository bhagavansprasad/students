#include <stdio.h>
#include <stdlib.h>

#define MSGSIZE 30


int child(int rfd, int wfd)
{
	char *msg2 = "hi,rajini";
	char cbuff[MSGSIZE];
	int retval = 0;

	printf("C: going to read...\n");
	retval = read(rfd, cbuff, MSGSIZE);
	printf("C: After reading retval :%d\n", retval);

	cbuff[retval] = '\0';
	printf("C : cbuff :%s\n", cbuff);

	printf("C: going to write...\n");
	retval = write(wfd, msg2, MSGSIZE);
	if (retval < 0)
		perror("C: error in writing");
	printf("C: write retval :%d\n", retval);
	printf("C: exiting....\n");
}

int parent(int rfd, int wfd)
{
	char *msg1="hello,world#1";
	char pbuff[MSGSIZE];
	int retval = 0;

	printf("P: going to write...\n");
	retval = write(wfd, msg1,MSGSIZE);

	printf("P: write retval :%d\n", retval);
	printf("P: sleeping...\n");
	sleep(1);
	printf("P: After sleeping\n");

	printf("P: Before reading\n");
	retval = read(rfd, pbuff, MSGSIZE);
	pbuff[retval] = '\0';
	printf("P: After reading retval :%d\n", retval);
	printf("P : buff :%s\n", pbuff);
	printf("P: exiting....\n");
}

main()
{
	int p[2],pid;

	pipe(p);
	pid=fork();
	if(pid > 0)
	{
		parent(p[0], p[1]);
	}
	else
	{
		child(p[0], p[1]);
	}

	exit(0);
}
