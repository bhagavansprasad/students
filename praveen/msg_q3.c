#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

main()
{
	int msqid;
	key_t key = 25;
	msqid = msgget(key,IPC_CREAT|0466);

	if(msqid<0)
		perror("message failed");
	else
	printf("message queue is created with id %d\n",msqid);
}
