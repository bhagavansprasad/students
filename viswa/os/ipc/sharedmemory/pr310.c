#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

main()
{
	int shmid;
	char *ptr;

	shmid = shmget(200000,1, IPC_CREAT|0666);
	ptr = (char *)shmat(shmid, 0,0);
	printf("ptr->%u\n",ptr);
	read(0, ptr, 10);
	shmdt(ptr);
	write(1, ptr, 10);
	perror("complete:");
}
