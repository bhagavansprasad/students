#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
main()
{
	int msqid;
	msqid = msgget((key_t)13, IPC_CREAT);
	printf("Messge queue sucessful creat with key %d\n", msqid);
}

