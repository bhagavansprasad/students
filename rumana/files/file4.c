#include<stdio.h>
#include<fcntl.h>
main()
{
int fd,ln=12,r;
char buff[10];
fd=open("file2.c",O_RDWR,0);
printf("%d",fd);
while(1)
{
r=read(fd,buff,ln);
printf("%s",buff);
if(r<ln)
break;
}
close(fd);
}

