#include <stdio.h>

int ovc(int rfd)
{
	int pid, giffs;
	for(; ;)
	{
		read(pid, giffs);
		store_index_db();
		calc_cpu_occ();
		action();
	}
}
