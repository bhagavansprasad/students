#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
main()
{
	int semid;
	ushort val[5];
	semid = semget(0x20,5,0666|IPC_CREAT);
	semctl(semid,0,SETVAL,1);
	semctl(semid,1,SETVAL,2);
	semctl(semid,2,SETVAL,3);
	semctl(semid,3,SETVAL,4);
	semctl(semid,4,SETVAL,5);
	semctl(semid,0,GETALL,val);
	printf("val1:%d\tval2:%d\nval3:%d\tval4:%d\nval5:%d\n",val[0],val[1],val[2],val[3],val[4]);
}
