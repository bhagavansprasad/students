#include "stdio.h"
#include "fcntl.h"
main()
{
char buff[100];
int fd,fd1,r,w,len=10;
fd=open("a.c",O_RDONLY);
fd1=open("b.txt",O_RDWR|O_CREAT,0777);
while(1)
{
r=read(fd,buff,len);
buff[r]='\0';
w=write(fd1,buff,r);
if(r<len)
break;
}
close(fd1);
close(fd);
}
