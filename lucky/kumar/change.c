#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int r,w,fd=0,fd1=0;
	char buff[100];
	fd=open("t.txt",0,O_RDONLY);
	fd1=open("k.txt",O_CREAT|O_WRONLY,0777);
	r=read(fd,buff,10);
	buff[r]='\0';
	w=write(fd1,buff,r);
	lseek(fd,-10,SEEK_END);
	r=read(fd,buff,10);
	buff[r]='\0';
	w=write(fd1,buff,r);
	close(fd);
	close(fd1);
}
