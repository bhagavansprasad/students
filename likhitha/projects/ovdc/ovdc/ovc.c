#include <stdio.h>

struct ovdc_data data[100];
int pid_count = 0;

int ovc(int rfd)
{
	int pid, giffs ;
	ovdc_db data;

	for( ; ; )
	{
		//TODO:
		//read structure with pid and giffs from pipe
		//
		read(rfd, &data, sizeof(data));
		cpu_occ = store_n_get_cpu_occ(data.pid, data.giffs);
		printf("%d:%d\n", pids[i], cpu_occ);/

#if 0
		read(pid,giffs);
		store_in_db();
		calculate_cpu_occ();
		action();
#endif
	}
}
