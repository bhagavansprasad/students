#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int fd;

void parent(int semid);
void child(int semid);

int main()
{
        int semid;
        int pid;
        int retval;

        semid = semget(0x25, 1, IPC_CREAT | 0666);

        fd = open("x.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);

        semctl(semid, 0 ,SETVAL , 0);

        retval = semctl(semid, 0 ,GETVAL , 0);

        printf("--> Main : retval : %d\n", retval);

        pid = fork();

        if(pid > 0)
        {
                parent(semid);
        }

        else
        {
                child(semid);
        }
        return 0;
}
