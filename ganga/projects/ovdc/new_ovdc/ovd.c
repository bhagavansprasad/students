#include <stdio.h>
#include "defs.h"
#include "fcntl.h"

int get_cpu_giffs_sum(char *buff)
{
	int words = 0, sum = 0, i = 0, value = 0, j = 0;
	char temp[100] = " ";
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
		//i++;	
		j = 0;
	}
	//printf("sum=%d\n",sum);

	return sum;
}


int get_giffs_by_pid(int pid)
{
	int fd = -1, retval = 0, len = 2048, giffs_count;
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

int ovd(int wfd, int *pids, int proc_count)
{
	int pid, giffs;
	int i = 0;
	struct ovdc_db data;

	while(1)
	{
		for (i = 0; i < proc_count; i++)
		{
			printf("-->%d. %d\n", i+1, pids[i]);
			giffs = get_giffs_by_pid(pids[i]);
				
			data.pid = pids[i];
			data.giffs = giffs;

			write(wfd, &data, sizeof(data));

			//TODO:
			//Fill the sturcture with pid and giffs
			//write on to pipe

		}
		sleep(1);
	}


#if 0
	for( ; ; )
	{
		open();
		read();
		send(pid,giffs);
		sleep();
		return 0;
	}
#endif
}
