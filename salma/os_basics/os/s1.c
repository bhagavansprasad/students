#include<stdio.h>
#include<fcntl.h>
main()
{
int fd,r;
char buff[100];
fd=open("t.txt",O_RDONLY,0777);
printf(" fd :%d \n",fd);
r=read(fd,buff,10);
printf("fd after read :%d\n",fd);
}
