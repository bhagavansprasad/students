#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

main()
{
	int shmid1,shmid2,i;
	char *ptr1,*ptr2;

	shmid1 = shmget((key_t)10,60,IPC_CREAT|0666);
	shmid2 = shmget((key_t)11,60,IPC_CREAT|0666);
	
	if(shmid1 < 0 || shmid2 < 0)
	{
		perror("shmget failed");
		exit(0);
	}
	
	ptr1 = shmat(shmid1,0,0);
	ptr2 = shmat(shmid2,0,0);
	
	strcpy(ptr2,"B");
	
	for(i=0;i<10;i++)	
	printf("%d.%s\t",i+1,ptr1);
	printf("\n");
}
