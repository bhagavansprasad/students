#include <stdio.h>
#include<fcntl.h>
main()
{
int fd=0;
char buff[100];
fd=open("t.txt.c",O_RDONLY);
read(fd,buff,30);
printf("%s",buff);
close(fd);
}

