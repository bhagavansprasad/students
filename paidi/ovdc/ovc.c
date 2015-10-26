#include "stdio.h"
#include "ovdc.h"
#include"signal.h"
int data_base[100][4]={0,0,0,0};
int no_of_entries;
ovdc_data data;

void ovc(int rfd)
{
	ovdc_data data;
	int cpu_usage,retval,i=0;

	while(1)
	{	
		i++;
		retval = read(rfd, &data, sizeof(data));
		if(data.pid != -1)
		{
			cpu_usage = cal_cpu_usage(data);
			printf("ovc: cpu_usage[%d] = %d\n", data.pid, cpu_usage);
			cpu_usage_overflow(cpu_usage);
		}
		else
		{
			printf("\n cpu usage calculated successfully\n");
			remove_killed_pid(data.pid);
		}
	}
}
int cal_cpu_usage( ovdc_data data)

{
	int i,j,cpu_usage,flag = 0;
	for(i = 0,j=0; i < no_of_entries; i++)
	{	
		if(data_base[i][j] == data.pid)
		{	
			flag = 1;
			break;
		}
	}
	if(flag)
	{
		cpu_usage = ( data.giffs - data_base[i][j+1]);

		data_base[i][j+1] = data.giffs;

		data_base[i][j+2] = 1;

		if(data_base[i][j+3]!=0)

			data_base[i][j+3]=data_base[i][j+3]-1;

		return cpu_usage;


	}
	data_base[i][j] = data.pid;
	data_base[i][j+1] = data.giffs;
	data_base[i][j+2] = 1;

	no_of_entries++;	
	return 0;
}




int cpu_usage_overflow(int cpu_usage)
{
	ovdc_data data;
	if(cpu_usage<=30 && cpu_usage>=40)
	{
		printf(" the cpu usage of %d is minimum:\n",data.pid);
		return;
	}
	else if(cpu_usage<=41 && cpu_usage>=50)
	{
		printf("the pid is getting more cpu occupency ");
		int PRIO_PROCESS;
		int priority;
		priority=setpriority(PRIO_PROCESS,data.pid,19);
		return ;
	}
	else if(cpu_usage<=51 && cpu_usage>=60)
	{
		kill(data.pid,SIGSTOP);
		sleep(5);
		kill(data.pid,SIGCONT);
		return;
	}
}




int remove_killed_pid(int pid)
{
	int i;

	for(i=0;i<no_of_entries ;i++)
	{	
		if(data_base[i][2] == 0)

			remove_entry(i);
	}
}			
void remove_entry(int i)
{
	int j =0;

	for(;i<3;i++)

		for(j = 0;j< 3 ;j++)

			data_base[i][j] = data_base[i+1][j+1];

	no_of_entries--;
}


