#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
main()
{
	int msqid;
	msqid = msgget((key_t)20,IPC_CREAT);
	printf("message queue is : %d\n", msqid);
}
