#include<stdio.h>
#include<fcntl.h>
main()
{
int fd1,fd2,r,w,len=10;
char buff[50];
fd1=open("c.txt",O_RDONLY,0);
fd2=open("c1.txt",O_CREAT|O_RDWR,777);
r=read(fd1,buff,len);
buff[r]='\0';
write(fd2,buff,r);
lseek(fd1,-11l,2);
r=read(fd1,buff,len);
buff[r]='\0';
write(fd2,buff,r);
close(fd1);
close(fd2);
}
