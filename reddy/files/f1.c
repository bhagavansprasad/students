#include "stdio.h"
#include "fcntl.h"
#include "fop.h"
main()
{
char buff[80];
int fd,fd1,r,w,l=10;
fd=aopen("reddy.txt",O_RDONLY,0);
fd1=aopen("vinay1.txt",O_RDWR|O_CREAT,0777);
r=aread(fd,buff,l);
buff[r]='\0';
w=awrite(fd1,buff,r);
alseek(fd,-10l,2);
r=aread(fd,buff,l);
buff[r]='\0';
w=awrite(fd1,buff,r);
aclose(fd1);
aclose(fd);
}
