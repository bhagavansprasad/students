#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
main()
{
	int i,msqid;
	key_t key=15;
	msqid=msgget(key,IPC_CREAT|0666);
	if(msqid<0)
	perror("message is failed");
	else
	printf("message queue is successfully created %d\n",msqid);

}
