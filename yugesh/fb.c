#include <stdio.h>
#include "fcntl.h"
main()
{
int length=20;
char buff[500];
int fd=open("x.txt",O_RDONLY);
int returnvalue=read(fd,buff,length);
if(returnvalue>0);
{
printf("%s",buff);
}
close(fd);
}
