#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
void main()
{
int fd=0,fd1=0,r,w,len=10;
char buff[500];
fd=open("t.txt",0,O_RDONLY);
fd1=open("a.txt",O_CREAT|O_WRONLY,0777);
r=read(fd,buff,len);
buff[r]="\0";
w=write(fd1,buff,r);
printf("%d",r);
printf("%s",buff);
close(fd);
}
