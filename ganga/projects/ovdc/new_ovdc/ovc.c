#include <stdio.h>
#include "defs.h"

int pid_count = 0;

int store_n_get_cpu_occ(int pid, int giffs)
{
	int i, cpu_occ = 0;
	struct ovdc_db d[100] = {0, 0};

	for(i = 0; i < pid_count; i++)
	{
		if (d[i].pid == pid)
		{
			cpu_occ  = giffs - d[i].giffs;
			d[i].giffs = giffs;

			return cpu_occ;
		}
	}
	
	for(  ; i < 100; i++)
	{
		d[i].pid = pid;
		d[i].giffs = giffs;
		pid_count++;

		return 0;
	}
}

int ovc(int rfd)
{
	int i, pid, giffs, cpu_occ;
	int pids[100] = {0};
	struct ovdc_db dta;
	
	while(1)
	{
		for( ; ; )
		{
			read(rfd, &dta, sizeof(dta));
			cpu_occ = store_n_get_cpu_occ(dta.pid, dta.giffs);

			if(cpu_occ > 0)
				printf("CPU_OCC : %d\n", cpu_occ);
		}
	}
}
