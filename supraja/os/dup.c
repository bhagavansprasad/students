#include <stdio.h>
#include "fcntl.h"
int main()
{
int fd,pid,nfd,rfd;
char buff[10];
pid=fork();
fd=open("t.txt",O_RDONLY);
nfd=dup(fd);
rfd=read(fd,buff,10);
rfd=read(nfd,buff,10);
printf("%s\n",buff);
//printf("%s",buff);


}

