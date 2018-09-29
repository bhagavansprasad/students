#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
main()
{
	int len=10,fd1,fd2,retnval;
	char buff[512];
	fd1=open("g.txt",O_RDONLY);
	fd2=open("2.txt",O_CREAT|O_RDWR,0644);
	while(1)
	{
	retnval=read(fd1,buff,len);
	buff[retnval]='\0';
	//printf("%s",buff);
//	write(fd2,buff,retnval);
	if(retnval>0)
	 	write(fd2,buff,retnval);
	else
		break;
	//else
	//	write(fd2,buff,retnval);

	}
	close(fd1);
	close(fd2);
}
