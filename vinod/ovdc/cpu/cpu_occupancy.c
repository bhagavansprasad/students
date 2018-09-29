#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFF_SIZE 100

int main(int argc , char *argv[])
{
        int pid;
        int fd;
        int rdval;
        int i,j;
		int count;
		int flag;
        unsigned long int cpu1,cpu2;
        long int cpu3,cpu4;
        int old_cpu = 0, new_cpu, cpu;
        char buff[BUFF_SIZE+1];
        char string[20];

        pid = atoi(argv[1]);
		printf("pid : %d\n", pid);
        fd = open("/proc/pid/stat", O_RDONLY);
		printf("fd : %d\n", fd);
        if(fd < 0)
        {
                perror("Unable to open stat file : ");
                exit(1);
        }
        for(;;)
        {
                flag++;
                while(1)
                {
                        rdval = read(fd, buff, BUFF_SIZE);
                        buff[BUFF_SIZE] = '\0';

                        for(i=0 ; i<=BUFF_SIZE ; i++)
                        {
                                if(buff[i] != ' ' && buff[i] != '\0')

                                 {       for( ; buff[i] != ' ' && buff[i+1] != '\0'; i++,j++)
                                        {
                                                if(count >= 13 && count <=16)
                                                        string[j] = buff[i];
                                        }
                                }
                        }

                        if(rdval < sizeof(BUFF_SIZE))
                                break;
                }
                string[j] = '\0';
                sscanf(string, "%lu %lu %ld %ld", &cpu1, &cpu2, &cpu3, &cpu4);
                printf("cpu1 : %lu, cpu2 : %lu, cpu3 : %ld, cpu4 : %ld\n", cpu1, cpu2, cpu3, cpu4);
                new_cpu = cpu1 + cpu2 + cpu3 + cpu4;
                if(flag > 1)
                {
                        cpu = new_cpu - old_cpu;
                        printf("The CPU  usage of process %d is %d in \n", pid, cpu);
                }
                old_cpu = new_cpu;
                sleep(1);
        }
        return 0;
}
