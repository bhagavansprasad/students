#include<stdio.h>
#include<fcntl.h>
#include<errno.h> 
main()
{
	int fd,fd1,l=10,r,w;
	char buf[100];
	fd=open("first.txt",O_RDONLY);
	fd1=open("new.txt",O_RDWR|O_CREAT,0777);
		r=read(fd,buf,l);
		buf[r]='\0';
		w=write(fd1,buf,r);
	lseek(fd,-10l,2);
		r=read(fd,buf,l);
		buf[r]='\0';
		w=write(fd1,buf,r);
	if(w<0)
	{
		printf("not written:");
		printf("%d",errno);
	}
	close(fd);
}

