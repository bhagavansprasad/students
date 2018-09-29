#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>


main()
{
	int semid , nsem , nsemset , flag ,key;

	nsem = 1;
	flag = 0666 |IPC_CREAT;

	for( nsemset = 0 ;;nsemset++)
	{
		key = (key_t)nsemset;
		semid = semget( nsemset , nsem , flag);

		if( semid > 0)
			printf("\n created semaphore with ID : %d\n ", semid);
		else
		{
			printf(" maximum no .  of semaphore set are %d\n", nsemset);
			exit(0);
		}
	}
}
