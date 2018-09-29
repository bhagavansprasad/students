#include"stdio.h"
#include"sys/types.h"
#include"sys/ipc.h"
#include"sys/msg.h"
#include"string.h"
#include"structure.h"

main()
{
	int msgqid;
	msgqid=msgget((key_t)10,IPC_CREAT|0666);
	if(msgqid<0)
		perror("message get failed");
	for(;;)
	{
		if((msgrcv(msgqid,&recv,sizeof(struct data),1,0))==-1)
			perror("message receive failed");
		printf("%s my pid ==%d \n",recv.d.mtext,recv.d.cpid);
		send.mtype=recv.d.cpid;
		strcpy(send.d.mtext,"hi client im fine");
		if((msgsnd(msgqid,&send,sizeof(struct data),0))==-1)
			perror("message send failed");
	}
}
