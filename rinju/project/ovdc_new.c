#include <stdio.h>
#include <stdlib.h>
#include<fcntl.h>
#include <unistd.h>
#include"ovdc.h"
#define SIZE 2
int get_giff(int pid);
pid_giff_db arr[SIZE] = {0};
int pid_count = 0;
//int i=0 ;

int store_n_get_cpu_occpancy(int pid, int new_giffs)
{
	int	i, j,diff = 0;
		
		for(j = 0; j < pid_count; j++)
		{

			if (arr[j].pid == pid)
			{
				diff = new_giffs -arr[j].giffs;
				arr[j].giffs = new_giffs;
				printf(" diff = %d ",diff);
				//take the diff between old and new value
				//replace old giffs with current giffs
				//return diff
			}
		}

	for(;i<SIZE;i++)

{
		arr[i].pid = pid;
		arr[i].giffs = new_giffs;
		pid_count++;
		printf("cpu occupancy =0");
		printf(" old giff=%d ",arr[i].giffs);
		printf("pid = %d ",arr[i].pid);
		printf("p_c=%d ",pid_count);
		return 0;
	}

				return diff;
	//Its a new pid
	//Make a new entry in db
	//increment pid_count
	//return cpu occpance as 0
}



int get_cpu_giffs_sum(char *buff)
{
	int words=0, sum = 0 , i = 0, j = 0, value = 0;
	char temp[100] = "";

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
		//    i++;   
		j = 0;

	}
	printf("sum=%d\n",sum);
	//     p=sum;
	//   diff=p-q;
	//  printf("diff=%d\n\n",diff);
	//q=p;
	sleep(2);
	//return diff;
	return sum;
	}
int get_giff(int pid)
{
	int fd , x, retval=0,len=2000  ,giffs;
	char buff[1024];
	char temp1[1000] = "";
	for(x=0;x<10;x++)
	{
		sprintf(temp1,"/proc/%d/stat",pid);
		fd=open(temp1,O_RDONLY);


		if( fd < 0)
			printf( "open failure\n");

		retval = read(fd , buff, len);
		buff[retval] = '\0';
		//printf("%s", buff);
		//printf("%s\n", pbuff);
		giffs = get_cpu_giffs_sum(buff);
		close(fd);
	}
		return giffs;
}

int main(int argc,char *argv[])
{   
	int giffs, i,diff;
	int pid[5];   
	while(1)
	{
		for(i=1;i<argc;i++)
		{
			pid[i-1]=atoi(argv[i]);
			printf("pid =  %d\n ",pid[i-1]);
			giffs=get_giff(pid[i-1]);
			diff = store_n_get_cpu_occpancy( pid[i-1],giffs);


			//printf(" %d ",giffs);
			printf(" %d ",diff);


		}
	}	
}	


