#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
main()
{
	key_t key = 100;
	int i, msqid;
	for(i = 0; i < 50; i++)
	{
		msqid = msgget(key, 0666 || IPC_CREAT);
		if(msqid < 0)
		{
			perror("msgget failed\n");
			exit(1);
		}
		printf("msqid = %d\n", msqid);
		if(msgctl(msqid, IPC_RMID, 0) < 0)
		{
			perror("msgctl failed\n");
			exit(1);
		}
	}
}
