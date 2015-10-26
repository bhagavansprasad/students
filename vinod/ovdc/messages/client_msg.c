#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include "structs_msg.h"

int main(int argc, char *argv[])
{
	int pid;
	key_t k = 10;
	int flag = 0666;
	int msgqid;
	op op1;
	reply re1;
	
	pid = getpid();

	if((msgqid = msgget(k, flag)) < 0)
	{
		perror("--> C :Error in creating msg queue");
		exit(1);
	}

	printf("msqid : %d\n", msgqid);
	
	op1.pid = pid;
	op1.first = atoi(argv[2]);
	op1.second = atoi(argv[3]);
	strcpy(op1.cmnd, argv[1]);
	
	printf("--> C : pid : %d, first : %d, second : %d, cmnd : %s\n", op1.pid,
	op1.first, op1.second, op1.cmnd);

	if(msgsnd(msgqid, &op1, sizeof(op1), IPC_NOWAIT) < 0)
	{
		perror("--> C : Error in sending to queue\n");
		exit(1);
	}
	
	sleep(1);
	
	for(;;)
	{
		if(msgrcv(msgqid, &re1, sizeof(re1), 0, IPC_NOWAIT) < 0)
		{
			perror("--> C : Error in receiving from queue\n");
			exit(1);
		}
		
		
		if(re1.rpid == pid)
		{
			printf("--> C : %s of %d and %d is %d\n", op1.cmnd, op1.first, op1.second, re1.result);
			exit(1);
		}

		sleep(1);
	}
	return 0;
}
