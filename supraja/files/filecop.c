#include<stdio.h>
#include<fcntl.h>
main()
{
int fd1,fd2,r,len=10;
char buff[100];
fd1=open("simple.txt",O_RDONLY,0);
fd2=open("sample.txt",O_CREAT|O_RDWR,777);
while(1)
{
r=read(fd1,buff,len);
buff[r]='\0';
write(fd2,buff,r);
if(r<len)
break;
}
close(fd1);
close(fd2);
}
