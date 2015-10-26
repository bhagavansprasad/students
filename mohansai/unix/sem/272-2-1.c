#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"
#include "sys/ipc.h"
#include "sys/sem.h"
#include "stdlib.h"
main(int argc, char *argv[])
{
	int semid, val, set_semctl, get_semctl, i=0;
	
	val=atoi(argv[1]);

	semid=semget((key_t)0x21, 1,IPC_CREAT|0666);
	if(semid<0)
	{
		perror("there is a error in creating the semget");
		exit(1);
	}
	while(i++ < 10)
	{
		set_semctl = semctl(semid, 0, SETVAL, val+i);
		get_semctl = semctl(semid, 0, GETVAL, 0);
		printf("set_msgclt--> %d  \r\n  set_msgctl---> %d\r\n",	set_semctl, get_semctl);
		sleep(3);
	}
}

