#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <time.h>
#include <signal.h>
struct data
{
	int pid;
	int giffe;
	//int time_cunt;
};

struct data base;
int data_base[4][200];

int ovc(int p)
{
	int i=0,j=0;
	int susid;
	int fd,lrt;
	int prd=0;
	int sp,gp;
	char log[56];
	int cpu_ocpny;
	time_t now;
	fd = open("log.txt",O_RDWR|O_CREAT|O_APPEND,0777);
	if(fd == -1)
	{
		perror("opening log file failed");
	}
	for(i=0;j=0;;i++)
	{
		//for(j=0;j<4;j++)
		{
			prd = read(p,&base,sizeof(base));
			if(prd == -1)
			{
				perror("reading from the pipe failed");
				exit(0);
			}
			data_base[i][0] = base.pid;
			data_base[i][j+1] = base.giffe;
			//	printf("database [%d][%d] is %d\n",i,0,data_base[i][0]);
			//	printf("database [%d][%d] is %d\n",i,j+1,data_base[i][j+1]);
		}
		//printf("1st data_base[%d][%d] = %d\n",i,j,data_base[i][j]);
		//printf("2st data_base[%d][%d] = %d\n",i,j-1,data_base[i][j-1]);

		if(j == 4)
		{
			cpu_ocpny = data_base[i+1][j] - data_base[i+1][j-1];
			printf("cpu_occupancy = %d\n",cpu_ocpny);

			if(cpu_ocpny > 10 )
			{
				time(&now);
				sprintf(log,"\npid:%d\tcpu_occupancy:%d\ttime:%s\n",data_base[i][0],cpu_ocpny,ctime(&now));

				lrt=write(fd,log,sizeof(log));
				printf("%s\n",log);
			}

			if(cpu_ocpny > 10 && cpu_ocpny < 15)
			{
				sp = setpriority(PRIO_PROCESS,data_base[i][0],19);
				printf("setpriority = %d\n",sp);
				gp = getpriority(PRIO_PROCESS,data_base[i][0]);
				printf("getpriority = %d\n",gp);
			}
			else if (cpu_ocpny > 15)
			{
				printf("cpu_occupancy of process %d high so it is suspended\n",data_base[i][0]);	
				kill(data_base[i][0],SIGSTOP);
				//susid = data_base[i][0];
				//base.time_cunt = 3;
			}
			//base.time_cunt--;
			if(base.time_cunt == 0)
			{
				kill(susid,SIGCONT);
				printf("the process %d is continued \n",susid);
			}
		}
		if(i == 3 && j == 4)
		{
			j = 1;
		}

		if(i == 3)
		{
			i = -1;
			j++;
		}
	}

}

