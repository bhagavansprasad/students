#include<stdio.h>
#include<stdlib.h>
#include"defn_ovdc.h"
static int db_count;
static int cpuocc_db[3000][2];
static int pid_list[1000];

int ovc(int fd )
{
	int cpu_occ;
	ovdc_data r_data;
//	printf("Pids   Jiffs   Cpu Occupency \n");      
	read(fd,&r_data,sizeof(ovdc_data));
	cpu_occ = store_jiffs_to_db_by_pid(r_data.pid,r_data.jiffs);
	printf(" %4d  %8d  %12d\n",r_data.pid,r_data.jiffs,cpu_occ);

}

static int store_jiffs_to_db_by_pid(int pid, int jiffs)
{
	int k = 0, diff = 0;

	for(k = 0;k <= db_count;k++)
	{	
		if(pid == cpuocc_db[k][0])
		{
			diff = (jiffs - cpuocc_db[k][1]);
			cpuocc_db[k][1] = jiffs;
			return diff;
			
		}
	}
	if(k > db_count)
	{
	        cpuocc_db[k][0] = pid;
	        cpuocc_db[k][1] = jiffs;
	        db_count++;
		return 0;
	}
}

