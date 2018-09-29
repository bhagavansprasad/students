#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

main()
{
	int shmid;
	char *ptr;
	char *ptr1;
	shmid = shmget((key_t)1,30,IPC_CREAT|0666);
	ptr = shmat(shmid,0,0);
	printf("data from the server%s\n",ptr);
	strcpy(ptr1,"hi");
}
