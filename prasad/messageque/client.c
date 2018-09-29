#include"stdio.h"
#include"sys/types.h"
#include"sys/ipc.h"
#include"sys/msg.h"
#include"string.h"
#include"structure.h"

main()
{

	int msqid,pid;
	msqid=msgget((key_t)10,IPC_CREAT|0666);
	if(msqid<0)
		perror("msgget failed \n");

	pid=getpid();
	printf("client1 pid=%d \n",pid);
	send.mtype=1;
	send.d.cpid=pid;
	strcpy(send.d.mtext,"hi server hw ru im client");

        if((msgsnd(msqid,&send,sizeof(struct data),0))==-1)
		perror("message send failed");

	if((msgrcv(msqid,&recv,sizeof(struct data),pid,0))==-1)
		perror("message receive failed");
	printf("%s \n",recv.d.mtext);
}


