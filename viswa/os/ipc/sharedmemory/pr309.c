#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

main()
{
	int shmid,i;
	char *msg;

	shmid = shmget(200000,1, IPC_CREAT|0666);
	msg = (char *)shmat(shmid, 0,0);
	printf("msg->%u\n",msg);
	i = shmdt((char *)msg);
	printf("i->%d\n",i);
}
