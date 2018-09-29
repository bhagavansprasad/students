#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
main()
{
	int i, msqid;
	key_t key = 15;
	msqid = msgget(key, IPC_CREAT | 0666);
	printf("msqid is : %d\n", msqid);
	if(msqid < 0)
		perror("msgget failed");
	else
		printf("message queue successfully created with key : %d\n", msqid);

}
