#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
main()
{
	int qid,len;
	struct msqid_ds qstatus;
	struct
	{
		long mtype;
		char mtext[15];
	}message;
	printf("my process id is %d\n",getpid());
	qid=msgget((key_t)10,IPC_CREAT|0666);
	if(qid==-1)
	{
		perror("msgget failed");
		exit(1);
	}
	strncpy(message.mtext,"hello world\n",15);
	message.mtype=1;
	len=strlen(message.mtext);
	if(msgsnd(qid,&message,len,0)==-1)
	{
		perror("msgsnd failed");
		exit(1);
	}
	if(msgctl(qid,IPC_STAT,&qstatus)<0)
	{
		perror("msgctl failed");
		exit(1);
	}
	printf("\nmessage queue:%d\n",qid);
	printf("%d message(s) on queue \n",qstatus.msg_qnum);
	//pritnf("last msg.send by process:%3d at %s\n",qstatus.msg_ispid,ctime(&(qstatus.msg_stime)));
	//pritnf("last msg.recv by process:%3d at %s\n",qstatus.msg_irpid,ctime(&(qstatus.msg_rtime)));
}
