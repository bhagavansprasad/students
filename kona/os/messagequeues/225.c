#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
main()
{
	int msqid;
	key_t key=10;
	msqid=msgget(key,IPC_CREAT|IPC_EXCL);
	if(msqid<0)
	perror("msgget failed");
	else
	printf("message queue is created successfully with key %d\n",msqid);
}
