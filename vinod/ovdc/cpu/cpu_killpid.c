#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define BUFF_SIZE 1000

struct pidstatus
{        
	int pid;
	int rpid;
	int jiffy;
}data1, data2;

int get_jiffy(int fd);
int get_fd(int pid);
void ctrlmsg(int val, int pid);

int main(int argc, char *argv[])
{   
	int prid[argc-1];
	int i=0,j=0;
	int jiffy = 0;
	char pathname[argc-1][20];
	int db_jiffy[argc-1][argc-1];
	int fd;
	int pipe_fds[2];
	int fdr=0,fdw=0;
	int wrval = 0;
	int cpu_val = 0, pid = 0;

	if(pipe(pipe_fds) < 0)
	{
		perror("Error in creating a pipe :");
		exit(1);
	}

	fdr = pipe_fds[0];
	fdw = pipe_fds[1];

	memset(db_jiffy, 0, sizeof(int)*(argc-1)*(argc-1));

	printf("--> argc : %d\n", argc);

	for(i=0 ; i<(argc-1) ; i++)
		prid[i] = atoi(argv[i+1]);

	if(fork() > 0)
	{
		while(1)
		{
			for(i=0 ; i<(argc-1) ; i++)
			{
					fd = get_fd(prid[i]);

					if(fd < 0)
					{
						//printf("--> P : fd :%d\n", fd);
						data1.rpid = prid[i];
						data1.pid = 0;
						data1.jiffy = 0;
						if((wrval = write(fdw, &data1, sizeof(data1)) < 0))
						{
							perror("Error in writing to pipe : ");
							exit(1);
						}
						//printf("--> P : wrval :%d\n", wrval);
						continue;
					}
					else
					{
						//printf("--> p: fd :%d\n", fd);
						jiffy = get_jiffy(fd);
						//printf("--> P :jiffy %d\n", jiffy);
						data1.pid = prid[i];
						data1.rpid = 0;
						data1.jiffy = jiffy;
						if(write(fdw, &data1, sizeof(data1)) < 0)
						{
							perror("Error in writing to pipe : ");
							exit(1);
						}
					}
			}
		sleep(1);
	}
}

else
{
	while(1)
	{
		for(i=0 ; i<(argc-1) ; i++)
		{
			if(read(fdr, &data2, sizeof(data2)) < 0)
			{
				perror("Error in reading from pipe : ");
				exit(1);
			}
			if(data2.pid == 0)
				continue;
			else
			{
				db_jiffy[i][0] = data2.pid;
				cpu_val = data2.jiffy - db_jiffy[i][1];
				if(db_jiffy[i][1] != 0)
					printf("--> CPU occupancy of process %d is :%d\n",db_jiffy[i][0],(data2.jiffy - db_jiffy[i][1]));
				db_jiffy[i][1] = data2.jiffy;
				ctrlmsg(cpu_val, data2.pid);
			}
		}
		printf("\n");
		sleep(1);
	}
}
return 0;
}

void ctrlmsg(int val, int pid)
{
	if(val>10 && val<=30)
		printf("--> Process with pid :%d is using limited cpu\n", pid);
	else if(val>30 && val<=50)
		printf("--> Process with pid :%d is using fine cpu\n", pid);
	else if(val>50 && val<=70)
		printf("--> Put process with pid :%d in wait state\n", pid);
	else if(val>70 && val<=100)
		printf("--> Put process with pid :%d in suspend\n", pid);
}

int get_jiffy(int fd)
{
	int count=0;
	int i=0,j=0;
	int rdval=0;
	int pos=13;
	char string[20];
	unsigned long int cpu1,cpu2;
	long int cpu3,cpu4;
	char buff[BUFF_SIZE];

	rdval = read(fd, buff, BUFF_SIZE);
	buff[rdval] = '\0';

	for(i=0 ; buff[i] ; i++)
	{
		if(buff[i] != ' ' && buff[i] != '\0')
		{
			count += 1;

			for( ; buff[i] != ' ' && buff[i+1] != '\0'; i++)
			{
				if(count >= pos && count <= (pos+3))
				{
					string[j] = buff[i];
					string[j+1] = '\0';
					j++;
				}
			}
			if(count >= pos && count <= (pos+3))
			{
				string[j] = ' ';
				j++;
			}
			if(count == (pos+3))
			{
				sscanf(string, "%lu %lu %ld %ld", &cpu1, &cpu2, &cpu3, &cpu4);
				//printf("cpu1 : %lu, cpu2 : %lu, cpu3 : %ld, cpu4 : %ld\n", cpu1, cpu2, cpu3, cpu4);   
				return (cpu1+cpu2+cpu3+cpu4);
			}
		}
	}
	close(fd);
	return 0;
}

int get_fd(int pid)
{
	char pathname[20];
	int fd=0;

	sprintf(pathname, "%s%d%s", "/proc/",pid,"/stat");
	//printf("--> pathname : %s\n",  pathname);
	if((fd = open(pathname, O_RDONLY, 0444)) < 0)
	{
		//perror(" unable to open file : ");
		return -1;
	}
	//printf("--> GET FD :%d\n", fd);
	return fd;
}


