#include <stdio.h>
#include<fcntl.h>
#include"string.h"
#include"ovdc.h"
int get_giffs_by_pid(int);
struct pid_giffs_db giffs_data [10] = {0, 0};
struct ovdc_data data;
int pid_count = 0;
int i=0 ;

int store_n_get_cpu_occ(int pid, int giffs)
{
	int prev_giffs=0;
	int cpu_occ= 0;
	int i,pid_count=0;
	for(i = 0; i < pid_count; i++)
	{
		if (giffs_data[i].pid == pid)
		{
			//TODO:
			//take the diff between old and new value
			//replace old giffs with current giffs
			//return diff
			{
				cpu_occ  = giffs - giffs_data [i].giffs;
				giffs_data[i].giffs = giffs;
				giffs_data[i].cpu_occ= cpu_occ;

				return cpu_occ;
			}
		}
	}

	//TODO
	//Its a new pid
	//Make a new entry in db
	//increment pid_count
	//return cpu occpance as 0
	giffs_data[i].pid = pid;
	giffs_data[i].giffs = giffs;
	giffs_data[i].cpu_occ = cpu_occ;

	pid_count++;
	return 0;

}

int get_giffs_by_pid(int pid)
{
	int fd=-1 , words = 0, retval=0 ,len=2048 , giffs_count;
	char buff[4*1024];
	char temp[100] = "" ;

	sprintf(temp, "/proc/%d/stat", pid);

	fd = open(temp, O_RDONLY);
	if( fd < 0)
	{
		printf( "open failure\n");
		return ;
	}

	retval = read(fd, buff, len);
	retval[buff] = '\0';
	close(fd);

	printf("%s", buff);
	words = 0;
	//printf("%s\n", pbuff); 

	//TODO:
	giffs_count = get_cpu_giffs_sum(buff);
	return 0;
}

int get_cpu_giffs_sum(char *buff)
{
	int words=0 , sum=0 , temp[100] , i=0 , value=0 , j=0;
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
		value =(int) atoi(temp); //converting ascii to integer
		printf("value :%d\n", value);
		sum = sum + value;
		//	i++;	
		j = 0;

	}
	printf("sum=%d\n",sum);

	return sum;
}

int send_giffs(int pid, int giffs)
{
	int retval,i;
	struct ovdc_data data;		
	data.pid = pid;
	data.giffs = giffs;
	retval = write(&data, sizeof(data));

	if(retval >= 0)
	{
		printf("writing file is failed");
		return -1;
	} 

}

main(int argc, char *argv[])
{
	int giffs=0 ,i , proc_count = 2 ,retval , pid[5] ;
	int cpu_occ=-1 ,  prev_giffs=0;
	struct ovdc_data data;
	//TODO: Store pids that are pass as command line arguments
	//int pid[100]= {  };

	while(1)
	{
		for(i=1; i <= proc_count; i++)
		{
			pid[i] = atoi(argv[i]);
			giffs = get_giffs_by_pid(pid[i]);
			if(giffs!=-1)
				send_giffs(pid[i],giffs);
		}
		data.pid=-1;
		data.giffs=-1;
		retval = write(&data, sizeof(data));
	}
	cpu_occ=store_n_get_cpu_occ(pid[i], giffs);
	printf("difference %d\n",cpu_occ);
	sleep(5);
}

