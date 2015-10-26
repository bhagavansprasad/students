#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>

#define QKEY (key_t)0100
#define SEMKEY (key_t)0x30
#define QPERM 0666
#define MAXOBN 50
#define MAXPRIOR 10

struct q_entry
{
	long mtype;
	char mtext[MAXOBN+1];
};

main()
{
	int pid;

	switch(pid = fork())
	{
		case 0:
				setpgrp();
				serv();
				break;
		case -1:
				warn("fork to start server failed ");
				break;
	}

	exit(pid != -1 ?0:1);
}

proc_obj(msg)
char *msg;
{
	printf("%s\n",msg);
	system(msg);
}

static int r_qid =-1;
int fd;
serv()
{
	long pro_type,semid,retval;

	struct q_entry r_entry;
	struct sembuf sop;

	int mlen;
	char buff[10];

	fd = creat("ser.txt", O_WRONLY|O_CREAT|O_EXCL|0644);

	if(fd < 0)
	{
		printf("server already installed \n");
		exit(0);
	}
	else
	{
		printf("server process PID is %d\n", getpid());
	}

	sprintf(buff, "%d",getpid());
	write(fd, buff, sizeof(int));
	chmod("ser.txt",0400);

	if(r_qid == -1 && (r_qid = init_queue())== -1)
	{
		return(-1);
	}

	semid = semget(SEMKEY ,1,IPC_CREAT|QPERM);

	if(semid > 0)
		semctl(semid, 0, SETVAL,1);
	else
	{
		perror("server's semget failed ");
		exit(1);
	}

	for(;;)
	{
		pv(semid , -1);

		if((mlen = msgrcv(r_qid, &r_entry , MAXOBN , 0, MSG_NOERROR)) == -1)
		{
			perror("msgrcv failed :");
			return (-1);
		}
		else
		{
			printf("ser val.is : %d\n",semctl(semid, 0, GETVAL, 0));
			r_entry.mtext[mlen] = '\0';
			proc_obj(r_entry.mtext);
			printf("a.out over \n");
		}
		pv(semid, 1);
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

warn(s)
char *s;
{
	fprintf(stderr,"warning :%s\n",s);
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
