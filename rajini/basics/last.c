#include "stdio.h"
#include "fcntl.h"
main()
{
int fd,r,len=10;
char buff[100];
fd=open("p.txt.c",0,O_RDONLY);
r=read(fd,buff,len);
buff[r]='\0';
r=read(fd,buff,len);
lseek(fd,-10l,2);
r=read(fd,buff,len);
buff[r]='\0';
printf("%s\n",buff);
}
