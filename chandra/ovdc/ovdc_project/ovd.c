#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
	

	int rfd;
	int qid;
	char buff[500];

int reading(int fd);
int send_msg(int p,int fd);

int ovd(int p)
{
	int fd1,fd2,fd3,fd4;
	//int pid[4] = {};
	fd1 = open("/proc/3518/stat",O_RDONLY,0);
	if(fd1<0)
	{
		printf("fd1 == %d\n",fd1);
	}
	send_msg(p,fd1);

	fd2 = open("/proc/3527/stat",O_RDONLY,0);
	if(fd2<0)
	{
		printf("fd2 == %d\n",fd2);
	}
	send_msg(p,fd2);
	
	fd3 = open("/proc/3533/stat",O_RDONLY,0);
	if(fd3<0)
	{
		printf("fd3 == %d\n",fd3);
	}
	send_msg(p,fd3);
	
	fd4 = open("/proc/3539/stat",O_RDONLY,0);
	if(fd4<0)
	{
		printf("fd4 == %d\n",fd4);
	}
	send_msg(p,fd4);
return 0;
}

int reading(int fd)
{
		
	rfd = read(fd,buff,400);
	buff[rfd]='\0';
	return rfd;

}

int send_msg(int p, int fd)
{
	int rfu;
	int i;
	int wretval;
	int len;
	for(i = 1;i < 4;i++)
	{
		rfu = reading(fd);	
		//write(p,pid,10);

		len = sizeof(buff);
		
		wretval = write(p,buff,len);	
		if(wretval == -1)
		{
			printf("the write return valu is %d\n",wretval);
		}

		printf("%s\n",buff);	
		lseek(fd,0l,0);
		printf("\n");
		
		sleep(1);
	}
	return rfu;

}
