#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

main()
{
	int msqid;
	msqid = msgget((key_t)10 , IPC_CREAT);
	printf("message queue sucessfully created with key %d \n", msqid);
}
