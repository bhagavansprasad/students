#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
main()
{
		int len=10;
		char buff[512];
		int fd1=open("a.txt",O_RDONLY);
		int fd2=open("b.txt",O_CREAT);
		int rtval=read(fd1,buff,len);
		buff(rtval)='\0';
		write(fd2,buff,rtval);
		lseek(fd1,len,SEEK_END);
		int rtval=read(fd1,buff,len);
		buff(rtval)='\0';
		write(fd2,buff,rtval);
		close(fd1);
		close(fd2);
}
