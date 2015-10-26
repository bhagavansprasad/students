#include<stdio.h>
#include<fcntl.h>
main()
{
int fd,fd1,r,w;
char buff[100];
fd=open("t.txt.c",0,O_RDONLY);
r=read(fd,buff,20);
buff[r]='\0';
fd1=open("mini2.c",0,O_CREAT|O_RDWR);
w=write(fd1,buff,r);
printf("%s\n",buff);
close(fd1);
}

