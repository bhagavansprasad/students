#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
main()
{
	int qid,i;
	struct
	{
		long mtype;
		char mtext[25];
	}buff;

	qid=msgget((key_t)10,IPC_CREAT|0666);
	if(qid == -1)
	{
		perror("msgget failed \n");
		exit(1);
	}
	for(i=0;i<3;i++)
	{
		if(msgrcv(qid,&buff,15,0,IPC_NOWAIT|MSG_NOERROR)==-1)
		{
			perror("msg rcv failed \n");
			exit(1);
		}
		printf("message received %s \n",buff.mtext);
	}

}
