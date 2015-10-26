#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#define MSGSIZE 63
main(argc,argv)
	int argc;
	char *argv[];

{
	int fd,j,nwrite;
	char msgbuff[MSGSIZE];
	if(argc < 2)
	{
		printf("usage:<filename><message><message>...\n");
		exit(1);
	}
	if((fd = open("testfile",O_WRONLY)) < 0)
		perror("fifo open failed");
	for(j = 1; j < argc; j++)
	{
		strcpy(msgbuff,argv[j]);
		if((nwrite = write(fd, msgbuff,MSGSIZE+1)) <= 0)
			perror("message write failed");
	}
	exit(0);
}
