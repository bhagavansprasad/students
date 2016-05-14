#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
main()
{
	int i,msqid;
	key_t key =15;
	msqid = msgget(key,IPC_CREAT|0666);
	if(msqid<0)
		perror("msgget failed\n");
	else
		printf("msqid is : %d\n",msqid);
}
