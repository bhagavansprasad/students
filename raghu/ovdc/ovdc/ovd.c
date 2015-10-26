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
	int pid[4]={3447,3455,3461,3467};
	int fd;
	int i=0;
	char str[100];
	while(1)
	{
		sprintf(str,"/proc/%d/stat",pid[i]);
		fd = open(str,O_RDONLY,0);
		if(fd == -1)
		{
			perror("opening failed");
			exit(0);
		}
		send_msg(p,fd);
		i++;
		if(i == 4)
		break;
	}
	return;
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
	
		len = sizeof(buff);
		
		wretval = write(p,buff,len);	
		if(wretval == -1)
		{
			printf("the write return valu is %d\n",wretval);
		}
		lseek(fd,0l,0);
		sleep(1);
	}
	return rfu;

}
