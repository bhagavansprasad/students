#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
main()
{
	int msqid, i;
	key_t key = 15;
	msqid = msgget(key, IPC_CREAT|0);
	if(msqid<0)
	perror("msgget filed\n");
	else
	printf("Messge queue sucessful creat with key %d\n", msqid);
}

