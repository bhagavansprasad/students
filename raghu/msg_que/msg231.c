#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

main(argc,argv)
int 

argc;
char *argv[];
{
	int qid;
	struct msqid_ds qstatus;
	qid = msgget((key_t)atoi(argv[1]),IPC_CREAT);

	if(qid == -1)
	{
		perror("msgget failed");
		exit(1);
	}

	if(msgctl(qid,IPC_CREAT,&qstatus)<0)
	{
		perror("msgctl failed");
		exit(1);
	}
	printf("real user id of the queue creater : %d\n",qstatus.msg_perm.cuid);
	printf("real group id of the queue creater : %d\n",qstatus.msg_perm.cgid);
	printf("effective user id of the queue creater : %d\n",qstatus.msg_perm.uid);
	printf("effective group id of the queue creater : %d\n",qstatus.msg_perm.gid);
	printf("message queue id : %d\n",qid);
	printf("permissions : %o\n",qstatus.msg_perm.mode);
	printf("%d message(s) on queue \n\n",qstatus.msg_qnum);
	printf("last message send by process : %3d at %s\n",qstatus.msg_lspid,ctime(&(qstatus.msg_stime)));
	printf("last message received by process : %3d at %s\n",qstatus.msg_lrpid,ctime(&(qstatus.msg_rtime)));
	printf("current number of bytes on queue : %d\n",qstatus.msg_cbytes);
	printf("max number of bytes allowed on queues : %d\n",qstatus.msg_qbytes);
	
}
