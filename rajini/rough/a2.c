#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd;
	fd=open("t.txt",0,O_RDONLY);
	int pid=fork();
	if(pid==0)
	{
		char buff[200];
		int r,l=8;
		while(1)
		{
			r=read(fd,buff,l);
			buff[r]='\0';
			printf("r:%d\n  buff:%s\n",r,buff);
			sleep(1);
			if(r<l)
				break;
		}
		close(fd);
	}
	else
	{
		int r,l=2;
		char buff[200];
		sleep(1);
		while(1)
		{
			r=read(fd,buff,l);
			buff[r]='\0';
			printf("r:%d\n  buff:%s\n",r,buff);
			sleep(1);
			if(r<l)
				break;

		}
		close(fd);

	}

}
