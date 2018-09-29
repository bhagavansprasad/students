#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <sys/sem.h>



main()
{
	int semid;
	ushort val[5] = { 1, 2,3,4,5} , val1[5];

	semid = semget(0x20 , 5,0666 |IPC_CREAT);
	semctl(semid , 0 , SETALL,val);
	semctl(semid , 0 , GETALL,val1);

	printf("val1[0]->%d val1[1]->%d val1[2]->%d val1[3]->%d val1[4]->%d \n",val1[0],val1[1],val1[2],val1[3],val1[4]);

}

