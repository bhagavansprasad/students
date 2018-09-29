#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
main()
{
	char buff[100],buff1[100];
	int i;
	int fd1,fd2,rval,len=10;
	fd1=open("a.txt",O_RDONLY,0);
	fd2=open("r.txt",O_CREAT|O_RDWR,0777);
	while(1)
	{
		rval=read(fd1,buff,len);
		buff[rval]='\0';
	//	printf("%s",buff);
	    for(i=0;buff[i]!='\0';i++)
		{
		if(buff[i]>=65 && buff[i]<=90)
		buff1[i]=buff[i]+32;
		else if(buff[i]>=97 && buff[i]<=122)
		buff1[i]=buff[i]-32;
		else
		buff1[i]=buff[i];
		}
		buff1[i]='\0';
		write(fd2,buff1,rval);
		if(rval<len)
			break;
	}
	close(fd1);
	close(fd2);
}
