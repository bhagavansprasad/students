#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <string.h>

int main()
{
	int shmid=0;
	key_t k = 15;
	size_t s = 120;
	int flag = IPC_CREAT | IPC_EXCL | 0666;
	unsigned char *ptr;
	int i=0;
	char buff1[] = "HELLO world";
	char buff2[] = "HELLO auraa";


	if((shmid = shmget(k, s, flag)) < 0)
	{
		perror("--> W : Error in creating Shared Memory segment :");
		exit(1);
	}

	printf("--> W : shmid : %d\n", shmid);

	if((ptr = shmat(shmid, NULL, 0)) < 0)
	{
		perror("--> W : Error in attaching memory\n");
		exit(1);
	}
	
	for(i=0 ; i<256 ; i++)
	{
		*ptr = i;
		printf(" --> W : %d\n", *ptr);
		*ptr++;
		sleep(1);
	}
	
/*	strcpy(ptr, buff1);
	printf("--> W : 1buff : %s\n", ptr);
	ptr = ptr+12;
	strcpy(ptr, buff2);
	printf("--> W : 2buff : %s\n", ptr);
	ptr = ptr+10;

	for(i=0 ; i<5 ; i++)
	{
		strcpy(ptr, buff1);
		printf("--> W : ptr Buff : %s\n", ptr);
		ptr = ptr+12;
	//	sleep(2);
	}
*/
	return 0;
}

