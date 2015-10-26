#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

main()
{
	int msgid;
	key_t i;
	for(i=1;;i++)
	{
		if(msgid=shmget(i,1,IPC_CREAT|0666)<0)
		{
			printf("maximum no of segments %d\n",i);
			exit(1);
		}
	}

}
