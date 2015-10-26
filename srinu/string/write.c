#include<stdio.h>
#include<fcntl.h>
int main()
{
	int fd,fd1,r,w,len=2;
	char buff[100];
	fd=open("k.c",0,O_RDONLY);
	fd1=open("r.c",O_CREAT|O_WRONLY,0777);
	do
	{
		r=read(fd,buff,len);
		buff[r]='\0';
		w=write(fd1,buff,r);
	}while(r==len);

	close(fd1);
	close(fd);
}
