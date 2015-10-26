#include "stdio.h"
#include "stdlib.h"
#include "bsamp.h"

#include "sys/types.h"
#include "sys/ipc.h"
#include "sys/shm.h"

 int main()
 {
 	int running = 1;
	int ptr	;
	struct shared_use_st *shared_stuff;
	int shmid;


	shmid = shmget ( (key_t)10 , MAX , IPC_CREAT|0666 );
	if(shmid<0)
	{
		perror("error in file creation");
		exit(1);
	}

	ptr = shamt(shmid ,0,0);
	
	if(ptr==-1)
	{
		fprintf(stderr, "shmat failed \n");
		exit(EXIT_FAILURE);
	}
	
	printf("the memory attachment  at %d \n",ptr);
	
	shared_stuff = (struct shared_use_st *)ptr;

	shared_stuff->written_by_you=0;

	while(reading)
	{
		if(shared_stuff->written_by_you)
		{
			printf("you wrote %s".shared_stuff->some_text);

			sleep(5);

			shared_stuff->written_by_you;

			if(strncmp(shared_stuff->some_text, "end",3)==0)
			{
				return 0;
			}
		}
	}

}























