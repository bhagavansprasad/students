#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "defs.h"

int pid_count = 0;
struct ovdc_db data[100];

int store_n_get_cpu_occ(int pid, int giffs)
{
	int cpu_occ= 0;
	int i;

	for(i = 0; i < pid_count; i++)
	{
		if (data[i].pid == pid)
		{
			cpu_occ  = giffs - data[i].giffs;
			data[i].giffs = giffs;

			return cpu_occ;
		}
	}
	data[i].pid = pid;
	data[i].giffs = giffs;
	pid_count++;
	return 0;
}

int ovc(int rfd)
{
	int i;
	int pids[100];
	int cpu_occ = 0;
	struct ovdc_db data;

	for( ; ; )
	{
		//TODO:
		//read structure with pid and giffs from pipe
		
		read(rfd, &data, sizeof(data));
		cpu_occ = store_n_get_cpu_occ(data.pid, data.giffs);
		printf("%d:%d\n", pids[i], cpu_occ);

#if 0
		read(pid,giffs);
		store_in_db();
		calculate_cpu_occ();
		action();
#endif
	}
}
