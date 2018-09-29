#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd,pid=0;
	fd=open("t.txt",O_RDONLY,0777);
    int r,len=6;
	pid=fork();
	if(pid==0)
	{
		int r,len=6;
	  	char buff[100];
        //sleep(1);
		while(1)
		{
			r=read(fd,buff,len);
			buff[r]='\0';
			printf(" r ::%d\n buff ::%s\n",r,buff);
			sleep(2);
			if(r<len)
				break;
		}
		close(fd);
	}
	else
	{
		int r,len=5;
	    char buff[100];
		while(1)
		{
			r=read(fd,buff,len);
			buff[r]='\0';
			printf(" r ::%d\n buff ::%s\n",r,buff);
			sleep(2);
			if(r<len)
				break;
		}
		close(fd);
	}
}

