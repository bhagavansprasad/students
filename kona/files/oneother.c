#include<stdio.h>
#include<fcntl.h>
#include<errno.h> 
main()
{
	int fd,fd1,l=10,r,w,i,j;
	char buf[100];
	fd=open("first.txt",O_RDONLY);
	fd1=open("new.txt",O_RDWR|O_CREAT,0777);
	for(i=1;i<=5;i++)
	{
		r=read(fd,buf,l);
		buf[r]='\0';
		w=write(fd1,buf,r);
	}
	lseek(fd,-50l,2);
	for(j=1;j<=5;j++)
	{
		r=read(fd,buf,l);
		buf[r]='\0';
		w=write(fd1,buf,r);
	}
	if(w<0)
	{
		printf("not written:");
		printf("%d",errno);
	}
	close(fd);
}

