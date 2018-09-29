#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

extern int fd;

void child(int semid)
{
	int i = 0;
	int c = 1;
	char buff[15];
	for (;;)
	{
		sem_acquire(semid);
		for(; c <= 10 ; i++,c++)
		{
			sprintf(buff, "-->C : %d\n", i);
			write(fd, buff, sizeof(buff));
		}
		sem_release(semid);
		c=1;
		sleep(1);
	}
}

void parent(int semid)
{
	int i = 0;
	int c = 1;
	char buff[15];
	for (;;)
	{
		sem_acquire(semid);
		for(; c <= 10 ; i++,c++)
		{
			sprintf(buff, "-->P : %d\n", i);
			write(fd, buff, sizeof(buff));
		}
		sem_release(semid);
		c=1;
		sleep(1);
	}
}
