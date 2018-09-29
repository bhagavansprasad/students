#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
extern int fd;
extern struct sembuf sop;

void child()
{
	int semid, i=1, retval,c=1;
	char buff[15];

	semid = semget(0x25, 1, 0666);
LOOP:	sop.sem_num = 0;
		sop.sem_op = 0;
		sop.sem_flg = 0;
		semop(semid, &sop, 1);
		semctl(semid, 0, SETVAL, 1);

		for(; c <= 10 ; i++,c++)
		{
			sprintf(buff, "--> c : %d\n", i);
			write(fd, buff, sizeof(buff));
		}
		semctl(semid, 0, SETVAL, 0);
		sleep(1);
		c=1;
		goto LOOP;
}
