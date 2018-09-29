#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
main()
{
	int msqid;
	msqid=msgget((key_t)10,0);
	printf("message queue is created successfully with key %d\n",msqid);
}
