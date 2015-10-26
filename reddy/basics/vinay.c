#include <stdio.h>
#include"fcntl.h"
main()
{
char buff[100];
int fd=0;
fd=open("reddy.c",0,O_RDONLY);
read(fd,buff,40);
printf("%s",buff);
close(fd);
}
