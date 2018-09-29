#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
extern int fd;
extern struct sembuf sop;

void parent()
{
<<<<<<< sync_parent.c
	int semid, i, retval, c=1;
=======
	int semid, i=1, retval, c=1;
>>>>>>> 1.2
	char buff[15];

	semid = semget(0x25, 1, 0666);
<<<<<<< sync_parent.c
	retval = semctl(semid, 0, GETVAL, 0);
	if(retval == 0)
		semctl(semid, 0, SETVAL, 1);
	for(i=0 ; i<200 ; i++)
	{
		sprintf(buff, "--> p : %d\n", i);
		write(fd, buff, sizeof(buff));
		if(c > 10)
=======
LOOP:	sop.sem_num = 0;
		sop.sem_op = 0;
		sop.sem_flg = 0;
		semop(semid, &sop, 1);
		semctl(semid, 0, SETVAL, 1);

		for( ; c <= 10 ; i++, c++)
>>>>>>> 1.2
		{
<<<<<<< sync_parent.c
			semctl(semid, 0, SETVAL, 0);
			c=0;
			wait();
=======
			sprintf(buff, "--> p : %d\n", i);
			write(fd, buff, sizeof(buff));
>>>>>>> 1.2
		}
<<<<<<< sync_parent.c
		c++;
	}
=======
		semctl(semid, 0, SETVAL, 0);
		sleep(1);
		c=1;
		goto LOOP;
>>>>>>> 1.2
}
