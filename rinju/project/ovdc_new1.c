#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<fcntl.h>
#include"ovdc.h"
#define SIZE 10

int get_giff(int pid);
pid_giff_db arr[SIZE]={{0,0}};

int pid_count = 0;
int i=0 ;

int store_n_get_cpu_occpancy(int pid, int new_giffs)
{
	int diff = 0;

	for(i = 0 ; i < pid_count ; i++)
	{
		if (arr[i].pid == pid)
		{
			diff = new_giffs -arr[i].giffs;
			arr[i].giffs = new_giffs;
			
			return diff;
		}
	}
	arr[i].pid = pid;
	arr[i].giffs = new_giffs;
	pid_count++;
	//printf("cpu occupancy =0");
	return 0;
}

int get_cpu_giffs_sum(char *buff)
{
	int words=0, sum = 0 ,i = 0, j = 0, value = 0;
	char temp[100] = "";

	for( ; words != 13 && buff[i] != '\0'; i++) //getting 14th word
	{
		if (buff[i] == ' ')
			words++;
	}
	sum = 0;
	for(words = 0 ; words < 4; words++)
	{
		for( ; buff[i] != ' '; i++, j++)
			temp[j] = buff[i];
		temp[j] = '\0';
		i++;
		value =(int) atoi(temp); //converting ascii to integer
		//printf("value :%d\n", value);
		sum = sum + value;
		//    i++; 
		j = 0;

	}
	return sum;
}
int get_pids_from_args(int *pids, int argc, char *argv[])
{
	for(i = 1; i < argc; i++)
		pids[i-1] = atoi(argv[i]);

	return argc-1;
}

int get_giff(int pid)
{
	int fd,retval=0,len=2000  ,giffs;
	char buff[1024];
	char temp1[1000] = "";
	
	sprintf(temp1,"/proc/%d/stat",pid);
	fd=open(temp1,O_RDONLY);


	if( fd < 0)
		printf( "open failure\n");

	retval = read(fd , buff, len);
	buff[retval] = '\0';
	//printf("%s", buff);
	giffs = get_cpu_giffs_sum(buff);

	close(fd);
	return giffs;
}

int main(int argc,char *argv[])
{ 
	int giffs, i,proc_count,cpu_occ;
	int pid[5]; 
	printf("pid : %u \n", getpid());
	while(1)
	{
		proc_count = get_pids_from_args(pid, argc, argv);

		for (i = 0; i < proc_count; i++)
		{
			printf ("-->%d. %d\n", i+1, pid[i]);
		}

		for (i = 0; i < proc_count; i++)
		{
			pid[i]=atoi(argv[i+1]);
			//printf(" pid=%d ",pid[i]);
			giffs=get_giff(pid[i]);
			cpu_occ=store_n_get_cpu_occpancy( pid [i],  giffs);

			if(cpu_occ > 0)
				printf("cpu_occ= %d\n",cpu_occ);
			sleep(2);
		}
	}  
}  


