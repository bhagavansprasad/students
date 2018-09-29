#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
	int shmid=0;
	key_t k = 15;
	size_t s = 0;
	int flag = 0666;
	unsigned char *pr;
	int i=0, j=0;
	char buff1[12];

	if((shmid = shmget(k, s, flag)) < 0)
	{
		perror("--> W : Error in getting shmid : ");
		exit(1);
	}

	printf("--> R : shmid : %d\n", shmid);

	if((pr = shmat(shmid, NULL, SHM_RDONLY)) < 0)
	{
		perror("--> R : Error in attaching to address space : ");
		exit(1);
	}
	
	for(i=0 ; i<10 ; i++)
	{
		j = *pr;
		printf("--> R : %d\n", j);
		*pr++;
		//sleep(1);
	}

/*	for(i=0 ; i<7 ; i++)
	{
		for(j=0 ; j<12 ; j++)
		{	
			buff1[j] = *pr;
			*pr++;
		}
		buff1[j] = '\0';
//		strcpy(buff1, pr);
		printf("--> R : Buff1 : %s\n", buff1);
//		pr = pr+12;
	//	sleep(1);
	}
*/
	return 0;
}

