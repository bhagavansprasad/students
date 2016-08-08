#include <stdio.h>
#include "defs.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
struct giffs_db giffs_data[10];
int store_gifss_to_db_by_pid(int pid,int curr_giffs)
{
	int prev_giffs=0;
	int cpu_occ= 0;
	int i,noe=0;

	for(i = 0; i < noe; i++)
	{
		if(giffs_data[i].pid == pid)
		{
			cpu_occ  = curr_giffs - giffs_data[i].curr_giffs;
			giffs_data[i].curr_giffs = curr_giffs;
			giffs_data[i].cpu_occ= cpu_occ;

			return cpu_occ;
		}
	}
	giffs_data[i].pid = pid;
	giffs_data[i].curr_giffs = curr_giffs;
	giffs_data[i].cpu_occ = cpu_occ;

	noe++;
	return cpu_occ;
}

