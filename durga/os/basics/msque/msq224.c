#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
main()
{
	int msqid;
	msqid = msgget((key_t)13, 0);
	printf("Messge queue sucessful creat with key %d\n", msqid);
}

