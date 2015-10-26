#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
main()
{
	int msqid,i;
	key_t key=15;
	msqid=msgget(key,IPC_CREAT | 0666);
	if(msqid<0)
	 perror("msgget failed");
	else
	 printf("message queue successfully created with key %d\n",msqid);
}
