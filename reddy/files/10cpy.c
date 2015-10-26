#include "stdio.h"
#include "fcntl.h"
main()
{
int r,fd;
char buff[100];
fd=open("reddy.txt",0,O_RDONLY);
r=read(fd,buff,20);
buff[r]='\0';
printf("%s\n",buff);
lseek(fd,-30l,2);
r=read(fd,buff,15);
buff[r]='\0';
printf("%s\n",buff);
}
