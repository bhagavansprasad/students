#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

main()
{
	char *ptr;
	char *ptr1;
	int shmid;
	shmid = shmget((key_t)1,30,IPC_CREAT|0666);
	ptr = shmat(shmid,0,0);
	strcpy(ptr,"hello");
	printf("from the client %s\n",ptr1);
}
