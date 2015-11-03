#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<signal.h>
#include<stdlib.h>

#define QKEY (key_t)0100
#define QPERM 0666
#define MAXOBN 50
#define MAXPRIOR 10
static int s_pid =-1;
int fd;
main(argc,argv)
	int argc;
	char *argv[];
{
	int msq_id;
	struct msqid_ds msq_status;
	char buff[10];
	fd = open("ser.txt",O_RDONLY);
	if(fd < 0)
	{
		printf("server doesnot exists \n");
		exit(1);
	}
	read(fd,buff,sizeof(int));
	s_pid = atoi(buff);
	if((kill(s_pid,SIGTERM))== -1)
	{
		perror("halt server");
		exit(2);
	}
	else
	{
		unlink("ser.txt");
		printf("server halted \n");
	}
	if(atoi(argv[1])==1)
	{
		if((msq_id = init_queue())==-1)
		{
			perror("msgget failed ");
			exit(2);
		}
		if(msgctl(msq_id,IPC_RMID,&msq_status)< 0)
		{
			perror("msgctl failed ");
			exit(3);
		}
		printf("queue deleted \n");
	}
} 
init_queue()
{
	int queue_id;
	if((queue_id=msgget(QKEY,IPC_CREAT|QPERM)) == -1)
	{
		perror("msgget failed ");
		return(queue_id);
	}
}
