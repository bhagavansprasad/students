#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
main()
{
	int shmid;
	char *msg;
	shmid = shmget((key_t)1,10,IPC_CREAT|0666);
	msg = shmat(shmid,0,0);
	printf("%u\n",msg);
}
