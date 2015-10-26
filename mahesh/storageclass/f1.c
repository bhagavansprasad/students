#include<stdio.h>
#include"fcntl.h"
main()
{
int len=52;
char buff[2];
int fd = open ("m.txt",O_RDONLY);
int val=read (fd ,buff,len);
 printf("%s",buff);
close(fd);
}
