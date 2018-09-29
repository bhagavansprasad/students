#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
main()
{
	int msqid,i;
	key_t key=10;
	msqid=msgget(key,IPC_CREAT | IPC_EXCL);
	if(msqid<0)
	 perror("msgget failed");
	else
	 printf("message queue successfully created with key %d\n",msqid);
}
