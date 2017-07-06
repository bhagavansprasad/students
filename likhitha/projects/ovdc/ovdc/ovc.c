#include <stdio.h>

int ovc(int rfd)
{
int pid , giffs ;
	for( ; ; )
	{
		read(pid,giffs);
		store_in_db();
		calculate_cpu_occ();
		action();
	}
}
