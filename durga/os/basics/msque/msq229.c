#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#define PREM 0666
main()
{
	int msqid;
	key_t  i;
	for(i =0 ; i<10; i++)
	{
		msqid = msgget(i, IPC_CREAT|PREM);
		if(msqid<0)
		{
			perror("msgget filed\n");
			exit(1);
			}
			printf("msgget =  %d\n", msqid);
	}
}
