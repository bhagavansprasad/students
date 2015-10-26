#include <stdio.h>
#include "fcntl.h"
int main()
{
	int fd,pid,nfd,rfd;
	char buff[10];
	fd=open("t.txt",O_RDONLY);
	pid=fork();
	nfd=dup(fd);
	rfd=read(fd,buff,10);
	rfd=read(nfd,buff,10);
	printf("%s\n",buff);
	//printf("%s",buff);


}

