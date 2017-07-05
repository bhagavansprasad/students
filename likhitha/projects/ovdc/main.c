#include <stdio.h>
#include <fcntl.h>
#include "string.h"
#include "stdlib.h"
#include "unistd.h"
#include "ovdc.h"

struct ovdc_data data[100];

int pid_count = 0;
int i = 0 ;

int store_n_get_cpu_occ(int pid, int giffs)
{
	int cpu_occ= 0;
	int i,pid_count=0;

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

int get_cpu_giffs_sum(char *buff)
{
	int words=0 , sum=0 , i=0, value=0, j=0;
	char temp[100]= " ";
	for( ; words != 13 && buff[i] != '\0'; i++) //getting 14th word
	{
		if (buff[i] == ' ')
			words++;
	}				
	//printf("i     :%d\n", i); 
	//printf("words :%d\n", words); 
	//printf("%s\n", &pbuff[i]); 

	sum = 0;
	for(words = 0 ; words < 4; words++)
	{
		for( ; buff[i] != ' '; i++, j++)
			temp[j] = buff[i];
		temp[j] = '\0';
		i++;
		value = (int)atoi(temp); //converting ascii to integer
		//printf("value :%d\n", value);
		sum = sum + value;
		//	i++;	
		j = 0;

	}
	//printf("sum=%d\n",sum);

	return sum;
}

int get_giffs_by_pid(int pid)
{
	int fd=-1 , retval=0 ,len=2048 , giffs_count;
	char buff[4*1024];
	char temp[100] = "" ;

	sprintf(temp, "/proc/%d/stat", pid);

	fd = open(temp, O_RDONLY);
	if(fd < 0)
	{
		printf( "open failure\n");
		return -1;
	}

	retval = read(fd, buff, len);
	retval[buff] = '\0';
	close(fd);

	//printf("%s", buff);
	//printf("%s\n", pbuff); 

	giffs_count = get_cpu_giffs_sum(buff);
	return giffs_count;
}

int get_pids_from_args(int *pids, int argc, char *argv[])
{
	for(i = 1; i < argc; i++)
		pids[i-1] = atoi(argv[i]);

	return argc-1;
}

int main(int argc, char *argv[])
{
	int giffs=0 , j , proc_count ;
	int cpu_occ ;
	int pids[100];

	proc_count = get_pids_from_args(pids, argc, argv);

	for (i = 0; i < proc_count; i++)
	{
		printf ("-->%d. %d\n", i+1, pids[i]);
	}

	for( j = 0; j < 5; j++)
	{
		for (i = 0; i < proc_count; i++)
		{
			giffs = get_giffs_by_pid(pids[i]);
			printf("--> giffs : %d\n", giffs);
			cpu_occ = store_n_get_cpu_occ(pids[i], giffs);
			printf("-->cpu occupancy %d\n", cpu_occ);
			sleep(1);
		}
	}
	return 0;
}
