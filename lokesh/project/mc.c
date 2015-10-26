#include"stdio.h"
#include "fcntl.h"
main()
{
char buff[100];
int fd=0,fd1=0,r,w,len=5;
fd=open("t.c",0,O_RDONLY);
fd1=open("loke.c",O_RDWR|O_CREAT,0777);
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
