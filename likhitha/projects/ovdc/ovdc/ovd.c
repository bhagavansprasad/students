#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<fcntl.h>
#include"defs.h"
#define SIZE 10
int i;
 struct ovdc_db arr1[SIZE]={{0,0}};


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
//		printf("value :%d\n", value);
		sum = sum + value;
		//    i++; 
		j = 0;

	}
//	printf("sum=%d\n",sum);
//	sleep(2);
	return sum;
}


int get_giff(int pid)
{
	int fd ,  retval=0,len=1024  ,giffs;
	char buff[2*1024];
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

int ovd(int wfd, int *pids, int proc_count)

{ 
	int giffs, i;
	int pid[5]; 
	while(1)
	{
		for (i = 0; i < proc_count; i++)
		{
			giffs=get_giff(pids[i]);

			printf("pid = %d\n",pids[i]);
			printf("giffs = %d\n",giffs);

			arr1[i].pid = pids[i];
			arr1[i].giffs = giffs;

			write(wfd, &arr1, sizeof(arr1));

			//write on to pipe
		}
	sleep(1);
}
	  
} 

