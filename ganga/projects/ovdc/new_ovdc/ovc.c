#include <stdio.h>
#include "defs.h"

int db[100][3];
struct ovdc_db data[100]= {0};
int pid_count = 0;

int store_n_get_cpu_occ(int pid, int giffs)
{
	int i, cpu_occ = 0;

	for(i = 0; i < pid_count; i++)
	{
		if (db[i][0] == pid)
		{
			cpu_occ  = giffs - db[i][1];
			db[i][1] = giffs;
			
			//cpu_occ  = giffs - data[i].giffs;
			//data[i].giffs = giffs;

			return cpu_occ;
		}
	}
	db[i][0] = pid;
	db[i][1] = giffs;
	pid_count++;

	return 0;
}

int ovc(int rfd)
{
	int i, pid, giffs, cpu_occ;
	int pids[100] = {0};
	struct ovdc_db data;

	read(rfd, &db, sizeof(db));
	for( ; ; )
	{
		//TODO:
		//read structure with pid and giffs from pipe
		
		cpu_occ = store_n_get_cpu_occ(db[i][0], db[i][1]);
		printf("%d:%d\n",db[i][0], cpu_occ);
	}
}

#if 0
read(pid,giffs);
store_in_db();
calculate_cpu_occ();
action();
#endif
