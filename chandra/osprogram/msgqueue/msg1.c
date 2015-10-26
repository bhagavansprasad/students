#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
main()
{
	int i, msqid, pid;
	key_t key = 15;
	msqid = msgget(key, IPC_CREAT);
	pid = fork();
	
}
