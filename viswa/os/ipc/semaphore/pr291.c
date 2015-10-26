#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>

#define QKEY (key_t)0100
#define SEMKEY (key_t)0x20
#define QPERM 0666
#define MAXOBN 50
#define MAXPRIOR 10

struct q_entry
{
	long mtype;
	char mtext[MAXOBN+1];
};

static int f_qid = -1;
static int s_pid = -1;

main(argc, argv )
int argc;
char *argv[];
{
	int no_server=0,fd,semid;
	long pro_type;
	struct q_entry r_entry;
	int mlen;
	char buff[10];
	
	if(argc == 1)
	{
		printf("USAGE: flush <priority>\n");
		printf("where priority = 0-> flush all messages\n");
		printf("where priority = 0-> flush a particular priority \n");
		printf("where priority = 0-> flush all message below absoluete value of priority\n");
		exit(0);
	}



	if(f_qid == -1 && (f_qid = init_queue())== -1)
	{
		return(-1);
	}
	
	pro_type = atoi(argv[1]);

	fd = open("ser.txt", O_RDONLY);
	if(fd < 0)
		no_server = 1;
	if(no_server != 1)
	{
		semid = semget(SEMKEY ,1,0);
		pv(semid, -1);
	}


	for(;;)
	{
		
		if((mlen = msgrcv(f_qid, &r_entry , MAXOBN , pro_type,MSG_NOERROR|IPC_CREAT)) == -1)
		{
			break;
		}
		else
		{
			r_entry.mtext[strlen(r_entry.mtext)] = '\0';
			printf("command flushed -> %s \n",r_entry.mtext);
		}
	}
}

init_queue()
{
	int queue_id;

	if((queue_id = msgget(QKEY, IPC_CREAT|QPERM))==-1)
	{
		perror("msgget failed :");
		return (queue_id);
	}
}


pv(semid, val)
int semid,val;
{
	int retval;
	struct sembuf sop;
	sop.sem_num =0;
	sop.sem_op = val;
	sop.sem_flg = SEM_UNDO;

	retval = semop(semid , &sop,1);

	if(retval >0)
	{
		perror("semop failed :");
		exit(1);
	}
	return 0;
}
