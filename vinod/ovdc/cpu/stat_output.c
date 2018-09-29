#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFF_SIZE 1000

int main(int argc, char *argv[])
{
        int pid=0;
        int fd=0;
        int rdval=0;
        int i=0,j=0;
        int count=0;
        unsigned long int cpu1,cpu2;
        long int cpu3,cpu4;
        int old_cpu = 0, new_cpu, cpu;
        char buff[BUFF_SIZE+1];
        char string[50];
		char pathname[50];
		
        //pid = atoi(argv[1]);
       // printf("pid : %d\n", pid);
		
		sprintf(pathname, "%s%s%s", "/proc/",argv[1],"/stat");
		printf("pathname : %s\n", pathname);
        fd = open(pathname, O_RDONLY, 0444);
        printf("fd : %d\n", fd);


        if(fd < 0)
        {
                perror("Unable to open stat file :");
                exit(1);
        }
   
		while(1)
        {
                rdval = read(fd, buff, BUFF_SIZE);
                buff[BUFF_SIZE] = '\0';
				printf("-->rdval :%d\n", rdval);
				printf("-->buff :%s\n", buff);

                for(i=0 ; i<=BUFF_SIZE; i++)
                {
                        if(buff[i] != ' ' && buff[i] != '\0')
                        {
                                count += 1;
								printf("-->Count :%d\n", count);

                                for( ; buff[i] != ' ' && buff[i+1] != '\0'; i++)
                                {
                                        if(count >= 13 && count <=16)
                                         {
										  	printf("-->i :%d, j :%d\n", i, j);
											string[j] = buff[i];
											string[j+1] = '\0';
											printf("-->string :%s\n", string);
											j++;
																			
										}
                                }
								if(count >= 13 && count <=16)
                                {	
									string[j] = ' ';
									j++;
								}
								if(count == 16)
									goto LOOP;
                        }
                }

                if(rdval < BUFF_SIZE)
                        break;
        }
		LOOP:
        string[j] = '\0';
        sscanf(string, "%lu %lu %ld %ld", &cpu1, &cpu2, &cpu3, &cpu4);
        printf("cpu1 : %lu, cpu2 : %lu, cpu3 : %ld, cpu4 : %ld\n", cpu1, cpu2, cpu3, cpu4);
#if 0
        new_cpu = cpu1 + cpu2 + cpu3 + cpu4;
        if(flag > 1)
        {
                cpu = new_cpu - old_cpu;
                printf("The CPU  usage of process %d is %d in \n", pid, cpu);
        }
        old_cpu = new_cpu;
#endif
        sleep(1);
        return 0;
}

int get_cputime(char *ptr, int pos, int )
{
	
}
