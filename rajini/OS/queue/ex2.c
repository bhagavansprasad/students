#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

main()
{
 int msqid;

 msqid=msgget((key_t)10,0);
	printf("Message queue successfully created with key %d\n",msqid);
}