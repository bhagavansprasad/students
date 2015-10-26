#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
	
struct msg
{
	long type;
	char msge[500];
};

	int rfd;
	int qid;
	char buff[500];

struct msg que;
int reading(int fd);
int send_msg(int fd);

main()
{
	int fd1,fd2,fd3,fd4;


	qid = msgget((key_t)10,IPC_CREAT|0666);
	if(qid == -1)
	{
		perror("msgget failed");
		exit(0);
	}

	que.type = 1;

	fd1 = open("/proc/1517/stat",O_RDONLY,0);
	printf("fd1 == %d\n",fd1);
	send_msg(fd1);
	
	fd2 = open("/proc/1537/stat",O_RDONLY,0);
	printf("fd2 == %d\n",fd2);
	send_msg(fd2);
	
	fd3 = open("/proc/1544/stat",O_RDONLY,0);
	printf("fd3 == %d\n",fd3);
	send_msg(fd3);
	
	fd4 = open("/proc/1550/stat",O_RDONLY,0);
	printf("fd4 == %d\n",fd4);
	send_msg(fd4);
	

}

int reading(int fd)
{
		
	rfd = read(fd,buff,400);
	buff[rfd]='\0';
	return rfd;

}

int send_msg(int fd)
{
	int rfu;
	int i;
	int len;
	for(i=1;i<4;i++)
	{
		rfu = reading(fd);	
	
		strcpy(que.msge,buff);
		printf("%s\n",que.msge);

		len = strlen(que.msge);
		printf("length of a string is %d\n",len);

		msgsnd(qid,&que,len,0);

		lseek(fd,0l,0);
		printf("\n");
		sleep(1);
	}	
	return rfu;

}
