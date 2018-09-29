#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
main()
{
	int fd=-1,len=150,t,c=0,ret;
	char buff[10];
	fd=open("t.txt",O_RDONLY);
	while(1)
	{
		ret=read(fd,buff,len);
		printf("%s\n",buff);
		if(ret<len)
		{
			break;
		}
	}
	close(fd);
}
