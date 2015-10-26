#include<stdio.h>
#include<fcntl.h>
int main()
{
	int fd,fd1,r,w,len=2;
	
	char buff[100];
	
	fd=open("k.c",0,O_RDONLY);
	
	fd1=open("a.c",O_CREAT|O_WRONLY,0777);
	
	lseek(fd,2,SEEK_SET);
	
	r=read(fd,buff,len);
	
	buff[r]='\0';
	
	w=write(fd1,buff,r);
	
	lseek(fd,-2,SEEK_END);
	
	r=read(fd,buff,len);
	
	buff[r]='\0';
	
	w=write(fd1,buff,r);
	
	close(fd);
	
	close(fd1);
}
