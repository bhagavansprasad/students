#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
main()
{
	int msqid;
	msqid = msgget((key_t)10,IPC_CREAT|IPC_EXCL);
	if(msqid<0)
		perror("msgget failed");
	else
		printf("Message queue created with key %d\n ",msqid);
}
