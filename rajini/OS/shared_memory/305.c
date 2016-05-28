#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
main()
{
	char *ptr;
	int shmid,pid,nread;
	shmid = shmget((key_t)1,);
}
