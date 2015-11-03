#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
#include<fcntl.h>
#include<setjmp.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<errno.h>

#define QKEY (key_t)0100
#define QPERM 0666
#define MAXOBN 50
#define MAXPRIOR 10
struct q_entry
{
	long mtype;
	char mtext[MAXOBN+1];
};
static int f_qid =-1;
static int s_pid =-1;
main(argc,argv)
	int argc;
	char *argv[];
{
	int no_server = 0 ,fd;
	long pro_type;
	struct q_entry r_entry;
	int mlen;
	char buf[10];

	if(argc == 1)
	{
		printf("USAGE : flush <priority> \n");
		printf("where priority = 0 -> flush all messages \n ");
		printf("where priorty > 0 -> flush a particular priority \n");
		printf("where priorty < 0 -> flush all messages below absolute value of priorty \n");
		exit(0);
	}
	if(f_qid == -1 &&(f_qid = init_queue())==-1)
		return(-1);
	pro_type = atoi(argv[1]);
	fd=open("ser.txt",O_RDONLY);
	if(fd < 0)
		no_server =1;
	if(no_server != 1)
	{ 
		read(fd,buf,sizeof(int));
		s_pid = atoi(buf);
		kill(s_pid,SIGUSR1);
	}
	for(;;)
	{
		if(mlen =
				msgrcv((f_qid,&r_entry,MAXOBN,pro_type,MSG_NOERROR|IPC_NOWAIT))==-1)
		{
			break;
		}
		else
		{
			r_entry.mtext[strlen(r_entry.mtext)]='\0';
			printf("command flushed -> %s \n",r_entry.mtext);
		}
	}
	if(no_server != 1)
		kill(s_pid,SIGUSR2);
} 
init_queue()
{
	int queue_id;
	if((queue_id = msgget(QKEY,IPC_CREAT|QPERM))==-1)
	{
		perror("msgget failed ");
		return(queue_id);
	}
}
