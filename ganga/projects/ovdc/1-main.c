#include <stdio.h>
#include<fcntl.h>
#include"strings.h"
#include"stdlib.h"
#include"ovdc.h"

int pid[100]; 
pid_giffs_db data[10] = {0};

int pid_count = 0;

int store_n_get_cpu_occ(int pid, int giffs)
{
	int i, cpu_occ = 0, prev_giffs = 0;

	for(i = 0; i < pid_count; i++)
	{
		if (data[i].pid == pid)
		{
			//TODO:
			//take the diff between old and new value
			//replace old giffs with current giffs
			//return diff
			data[i].curr_giffs = giffs;
			cpu_occ = giffs - prev_giffs;
			prev_giffs = giffs;

			return cpu_occ;
		}
	}

	//TODO
	//Its a new pid
	//Make a new entry in db
	//increment pid_count
	//return cpu occpance as 0
}

int send_giffs(int pid, int giffs)
{
	int retval, i;
	ovdc_data data;		
	data.pid = pid;
	data.giffs = giffs;
	retval = write(&data, sizeof(data));

	if(retval >= 0)
	{
		printf("writing file is failed");
		return -1;
	} 
}

int get_giffs_by_pid(int pid)
{
	int fd, giffs_count = 0;
	int  words = 0, retval=0, x, i = 0, j = 0, value = 0, sum = 0, p = 0, q = 0, diff = 0,len = 2048;
	char buff[4*1024];
	char temp[100] = " ";

	sprintf(temp, "/proc/%d/stat", pid);

	fd = open(temp, O_RDONLY);

	if( fd < 0)
	{
		printf( "open failure\n");
		return -1;
	}

	retval = read(fd, buff, len);
	retval[buff] = '\0';

	printf("%s", buff);
	//printf("%s\n", pbuff); 
	close(fd);

	//TODO:
	giffs_count = get_cpu_giffs_sum(buff);
	printf("--> giffs count : %d\n", giffs_count);

	return giffs_count;
}

int get_cpu_giffs_sum(char *pbuff)
{
	int p, q, diff, j, sum, i, value,  words = 0;
	char temp[100] = " ";
	for( ; words != 13 && pbuff[i] != '\0'; i++) //getting 14th word
	{
		if (pbuff[i] == ' ')
			words++;
	}				
	//printf("i :%d\n", i); 
	//printf("words :%d\n", words); 
	//printf("%s\n", &pbuff[i]); 

	for(words = 0 ; words < 4; words++)
	{
		for( ; pbuff[i] != ' '; i++, j++)
			temp[j] = pbuff[i];
		temp[j] = '\0';
		i++;
		value = (int) atoi(temp); //converting ascii to integer
		printf("value :%d\n", value);
		sum = sum + value;
		//i++;	
		j = 0;
	}
	return sum;
	}

int main(int argc, char *argv[])
{
	int giffs, i, j, proc_count = 5, retval, cpu_occ;
	ovdc_data data;
	//TODO: Store pids that are pass as command line arguments

		printf("-->argc :%d\n", argc);
	
	if (argc < 2)
	{	

		printf("Invalid or Insufficient arguments\n");
		printf("Usage: ./a.out <pid> <pid>\n");
		exit(1);
	}

	for(i=0 ; i < argc ;i++)
	{
		pid[i] = atoi(argv[i+1]);
		
		printf("-->pid :%d\n", pid[i]);
	}

	printf("ovd pid : %d\n", getpid());

	for(j = 0; j < 3; j++)
	{
		for(i = 0; i < pid_count; i++)
		{
			giffs = get_giffs_by_pid(pid[i]);
			if(giffs != -1)
				send_giffs(pid[i],giffs);
		}
		data.pid = -1;
		data.giffs = -1;
		retval = write(&data, sizeof(data));
	}
	cpu_occ = store_n_get_cpu_occ(pid[i], giffs);
	printf("--> cpu_occupancy %d\n", cpu_occ);
	
	sleep(1);
	return 0;
}
