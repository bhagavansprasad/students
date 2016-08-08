#include <stdio.h>
#include<fcntl.h>
#include <stdlib.h>
#include "defs.h"

int noe=0;

int main(int argc, char *argv[])
{
	int curr_giffs=0,prev_giffs=0;
	int pid[10] = {-1}, i,j;
	int cpu_occ = -1;

	OVDC_DEBUG("-->argc :%d\n", argc);
	
	if (argc < 2)
	{	

		printf("Invalid or Insufficient arguments\n");
		printf("Usage: ./a.out <pid> <pid>\n");
		exit(1);
	}

	for(i=0 ; i < argc-1 ;i++)
	{
		pid[i] = atoi(argv[i+1]);
		
		printf("-->pid :%d\n", pid[i]);
	}

	for (j = 0 ; j <= 3 ; j++)
	{
		for(i=0 ; i < argc-1 ;i++)
		{
			curr_giffs = get_giffs_bypid(pid[i]);

			OVDC_DEBUG("---->curr_giffs:%d\n,--->prev_giffs:%d\n",curr_giffs,prev_giffs);
			
			cpu_occ = store_gifss_to_db_by_pid(pid[i], curr_giffs);
			
			printf("---->difference:%d\n", cpu_occ);

		}
		sleep(1);
	}
}

