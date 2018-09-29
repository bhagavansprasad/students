#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
main()
{
	int msqid;
	msqid=msgget((key_t)10,0);
	printf("message queue successfully created wiht key %d\n",msqid);
}
