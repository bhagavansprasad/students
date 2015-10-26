#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
main()
{
	int i, msqid;
	key_t key = 10;
	msqid = msgget(key, IPC_CREAT | IPC_EXCL);
	printf("message queue id is : %d\n", msqid);
	if(msqid < 0)
		perror("msgget failed");
	else
		printf("message queue successfully created with key : %d\n", msqid);

}
