#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
main()
{
	int msqid;
	key_t key=15;
	msqid=msgget(key,IPC_CREAT|0666);
	if(msqid<0)
	perror("msgget failed");
	else
	printf("message queue is created successfully with key %d\n",msqid);
}
