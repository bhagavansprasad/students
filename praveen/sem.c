#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

main()
{
	int semid,key,flag,nsem;
	key = (key_t)0x20;
	flag = IPC_CREAT|0666;
	nsem = 1;
	semid = semget(key,nsem,flag);
	printf("created semaphore with id : %d\n",semid);

}
