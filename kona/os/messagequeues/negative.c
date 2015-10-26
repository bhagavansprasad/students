#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
main()
{
	int msqid;
	key_t key=-1;
	msqid=msgget(key,IPC_CREAT|0644);
	if(msqid<0)
	perror("msgget failed");
	else
	printf("message queue successfully created with key %d\n",msqid);
}
