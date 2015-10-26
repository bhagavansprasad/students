#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

main()
{
	int qid,len;
	struct msqid_ds qstatus;
	struct {
		long mtype;
		char mtext[15];
	}message;

	printf("my process id is %d\n",getpid());
	qid = msgget((key_t)10,IPC_CREAT|0666);
	if(qid == -1)
	{
		perror("msgget failed");
		exit(1);
	}
	strncpy(message.mtext,"Hello world\n",15);
	message.mtype = 1;
	len = strlen(message.mtext);
	if(msgsnd(qid,&message,len,0)== -1)
	{
		perror("msgsnd failed");
		exit(1);
	}
	if(msgctl(qid,IPC_STAT,&qstatus)<0)
	{
		perror("msgctl failed");
		exit(1);
	}
	printf("\n message queue id :%d\n",qid);
	printf("%d message on queue \n\n",qstatus.msg_qnum);
	printf("last msg send by process :%d at %s\n",qstatus.msg_lspid,ctime(&(qstatus.msg_stime)));
	printf("last msg received by process :%d at %s\n",qstatus.msg_lrpid,ctime(&(qstatus.msg_rtime)));

}
