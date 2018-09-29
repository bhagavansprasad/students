#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>

main(int argc,char *argv[])
{
	int qid;
	struct msqid_ds qstatus;
	qid=msgget((key_t)atoi(argv[1]),IPC_CREAT);
	if(qid=-1)
	{
		perror("message failed");
		exit(1);

	}
	if(msgctl(qid,IPC_STAT,&qstatus)<0)
	{
		perror("msgctl failed");
		exit(1);
	}
printf("real user id of queue creator :%d\n",qstatus.msg_perm.cuid);
printf("real group id of queue creator:%d\n",qstatus.msg_perm.cgid);
printf("effective user id of queue creator :%d\n",qstatus.msg_perm.uid);
printf("effective group id of queue creator :%d\n",qstatus.msg_perm.gid);
printf("permissions :%o\n",qstatus.msg_perm.mode);
printf("\n message queued id is :%d\n\n",qid);
printf("%dmessage(s) on queue \n\n",qstatus.msg_qnum);
printf("last msg send by process:%3d at%s\n",qstatus.msg_lspid,ctime(&(qstatus.msg_stime)));
printf("last msg receive by process:%3d at%s\n",qstatus.msg_lrpid,ctime(&(qstatus.msg_rtime)));
printf("current no of bytes on queue %d\n",qstatus.msg_cbytes);
printf("max no of byte allowed on queue %d\n",qstatus.msg_qbytes);
}
