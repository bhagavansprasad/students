#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<fcntl.h>
#include"defs.h"
#define SIZE 10

int get_giff(int pid);
struct ovdc_db ar[SIZE]={{0,0}};

int pid_count = 0;
int i=0 ;

int store_n_get_cpu_occpancy(int pid, int new_giffs)
{
	int diff = 0;

	for(i = 0 ; i < pid_count ; i++)
	{
		if (ar[i].pid == pid)
		{
			diff = new_giffs -ar[i].giffs;
			ar[i].giffs = new_giffs;
			
			return diff;
		}
	}

	for( ;i<SIZE; i++)
	{
		ar[i].pid = pid;
		ar[i].giffs = new_giffs;
		pid_count++;
		//printf("cpu occupancy =0");
		return 0;
	}
}

int ovc(int rfd)
{ 
	int giffs, i,cpu_occ;
	int pid[5]; 
	struct ovdc_db arr;
	while(1)
	{


		for (; ; )

		{
			read(rfd, &arr, sizeof(arr));
			cpu_occ=store_n_get_cpu_occpancy( arr.pid ,  arr.giffs);

			if(cpu_occ > 0)
				printf("cpu_occ= %d \n ",cpu_occ);

		}

	}  
}   
