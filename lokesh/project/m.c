#include"stdio.h"
#include "fcntl.h"
main()
{
char buff[100];
int fd=0,r,len=5;
fd=aopen("t.c",0,O_RDONLY);
while(1)
{
r=aread(fd,buff,len);
buff[r]='\0';
printf("%s",buff);
if(r<len)
break;
}
aclose(fd);
}
