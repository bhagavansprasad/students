#include "stdio.h"
#include "unistd.h"
#include "ovdc.h"
#include "stdlib.h"
#include "sys/time.h"
#include "sys/resource.h"
#include "errno.h"
#include "signal.h"
//#define DEBUG 0 
#define MAX 65

int count=0,count1=0;
int list_of_pids[MAX][5] = { 0 , 0 };

void resume( int pid)
{
			//printf(" the process is activated--> %d\r\n",pid);
			kill(pid,SIGCONT);
}

void suspend ( int  pid )
{
	//printf(" the process is stoped--> %d\r\n",pid);
	kill(pid, SIGSTOP );
}

void reduce_pid(int pid)
{
	int i,j;

	for(i=0 ; i < count ; i++)
	{
		if(list_of_pids[i][0]!=pid)
		{
			for( j = i ; j < count ; j++ )
			{
				list_of_pids[j][0] = list_of_pids[j+1][0];
				list_of_pids[j][1] = list_of_pids[j+1][1];
				list_of_pids[j][2] = list_of_pids[j+1][2];
				count--;
				j--;
			}
		}
		
	}
}



void reduce(int  pid )
{
	int retval=0;

	setpriority(PRIO_PROCESS,pid,3);

	retval=getpriority(PRIO_PROCESS,pid);		

	if(errno==-1)
	{
		perror("there is an error in open a file ");
		exit(1);
	}
}		
void data_store(int pid, int gifs)

{
	int i=0, occupancy=0;
	
	ovdc_data ovcdata;
	for( i = 0 ; i < count ; i++ )
	{
		if(list_of_pids[i][0] == pid)
		{
			occupancy = gifs - list_of_pids[i][1];
#ifdef DEBUG
			printf("occupency-->%d\r\n",occupancy);
#endif
			list_of_pids[i][1]=gifs;

			if (occupancy > 30 )
				printf(" %d %d\r\n",list_of_pids[i][0],occupancy);
#ifdef DEBUG
			printf("occupency-->%d\r\n",occupancy);
#endif
			if ( occupancy >= 30  &&  occupancy <= 40 )
			{
				//printf("reducing the priority\n\r");
				reduce(list_of_pids[i][0]);
#ifdef DEBUG
				//	printf("-->more occupancy:-%d %d\r\n",list_of_pids[i][0],occupancy);
#endif			
			}else if ( occupancy >= 40  &&  occupancy <= 60 )
			{
				//printf("your process is occuping to much occupancy\n\r");
			}else if ( occupancy >= 60 )
			{
				suspend(list_of_pids[i][0]);
			
				list_of_pids[i][3]=5;
			}	
			else if(occupancy == 0)
			{
				if(list_of_pids[i][3] >= 1 )
	   			{
					if(list_of_pids[i][3] == 1)
					{	
	        			resume(list_of_pids[i][0]);
					}
					list_of_pids[i][3] = list_of_pids[i][3]-1;
	    		}
			}
			break;
#ifdef DEBUG
			printf("occupency-->%d\r\n",occupancy);
#endif
		reduce_pid(ovcdata.pid);
		}
	}	
	if(list_of_pids[i][0] != pid)
		{
			list_of_pids[i][0]=pid;
			list_of_pids[i][1]=gifs;
			count++;
		}
		return ;
}

void ovc(int read_fd)
{
	int j;

	ovdc_data ovcdata;

	for( j=0 ; ;j++ )
	{
		ovcdata.pid = 0;
		ovcdata.gifs = 0;
		if (read(read_fd, &ovcdata, sizeof(ovcdata)) <= 0)
		{
			perror("read failed\r\n");
			exit(1);
		}
	//	reduce_pid(ovcdata.pid);
#ifdef DEBUG
		printf("-->ovc %5d %5d\r\n", ovcdata.pid, ovcdata.gifs);
#endif
		data_store(ovcdata.pid, ovcdata.gifs);
	}
}
