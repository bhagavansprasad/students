#include<stdio.h>
#include<fcntl.h>
main()
{
int fd=0,r;
char buff[100];
fd=open("t.txt.c",0,O_RDONLY);
r=read(fd,buff,20);
buff[r]='\0';
printf("%s\n",buff);
close(fd);
}

