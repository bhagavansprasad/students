#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
main()
{
	int shmid;
	char *msg;
	shmid=shmget((key_t)1,10,IPC_CREAT|0666);
	printf("shmid is %d\n",shmid);
	msg=shmat(shmid,0,0);
	printf("msg pointer is %u\n",msg);
}
