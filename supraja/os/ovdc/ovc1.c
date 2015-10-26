#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

main()
{
	struct
	{
		long mtype;
		int pid;
		int giffies;
	}recv;
	int qid,f,x,y = 0,l=0,i,diff;
	qid = msgget((key_t)60,IPC_CREAT|0666);
	if(qid == -1)
	{
		perror("msgget failed");
		exit(1);
	}
	for(f=0;f<5;f++)
	{
		x = 0,y = 0,diff = 0;
		for(i = 0;i < 5;i++)
		{
			if(msgrcv(qid,&recv,120,0,IPC_NOWAIT)==-1)
			{
				perror("msgrcv failed");
				exit(1);
			}
			printf("giffies : %d\n",recv.giffies);
			x= recv.giffies;
			diff = x - y;
			y =recv.giffies;
			if(i >= 1)
				printf("pid : %d\tCPU OCCUPANCY : %d\n",recv.pid,diff);
		}
	}
}
