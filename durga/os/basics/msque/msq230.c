#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#define PREM 0666
main()
{
	int msqid, i;
	key_t  key = 20;
	for(i =0 ; i<10; i++)
	{
		msqid = msgget(key, IPC_CREAT|PREM);
		if(msqid<0)
		{
			perror("msgget filed\n");
			exit(1);
			}
			printf("msgget =  %d\n", msqid);
			if(msgctl(msqid, IPC_RMID, 0)<0)
			{
			perror("msgctl filed\n");
			exit(1);
				
			}
	}
}
