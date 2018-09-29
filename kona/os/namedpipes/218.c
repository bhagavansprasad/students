#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#define MSGSIZ 63
main(argc,argv)
int argc;
char *argv[];
{
	int fd,j,nwrite;
	char msgbuf[ MSGSIZ+1];
	if(argc<2)
	{
		printf("usage:<sreenu.txt><message><message>......\n");
		exit(1);
	}
	if((fd=open("sreenu.txt",O_WRONLY))<0)
	perror("pipe open failed\n");
	for(j=1;j<argc;argv[j])
	{
		strcpy(msgbuf,argv[j]);
		if(nwrite=write(fd,msgbuf,MSGSIZ+1)<=0)
		printf("message write failed\n");
	}
	exit(0);
}
