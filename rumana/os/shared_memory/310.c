#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
main()
{
	char *ptr;
	int shmid;
	shmid=shmget((key_t)1,1,IPC_CREAT|0666);
	printf("shmid is %d\n",shmid);
	ptr=(char *)shmat(shmid,0,0);
	printf("ptr is %u\n",ptr);
	read(0,ptr,10);
	write(1,ptr,10);
	shmat(ptr,0,0);
	write(1,ptr,10);

