#include<stdio.h>
#include<fcntl.h>
#include"headerfile.h"
main()
{
int fd1,fd2,r,len=10;
char buff[100];
fd1=aopen("simple.txt",O_RDONLY,0);
fd2=aopen("sample.txt",O_CREAT|O_RDWR,777);
while(1)
{
r=aread(fd1,buff,len);
buff[r]='\0';
awrite(fd2,buff,r);
if(r<len)
break;
}
aclose(fd1);
aclose(fd2);
}
