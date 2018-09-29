#include "stdio.h"
#include "stdlib.h"
#include <fcntl.h>
#include "unistd.h"
#define MAX_PIDS 10 

void display(int *list_of_numbers, int n)
{
	int i; 
	for( i = 0; i<=n ; i++ )
	{
		printf(" arr[%d] -->%d\n\r",i,list_of_numbers[i]);
	}
}

int parse_and_store(int *list_of_numbers, char *buffer)
{
	int i,count,word=0;

	for(i = 0; buffer[i]!='\0' && word >= 12 && word <= 16 ; i++)
	{
		if(buffer[i] == ' ')
			word++;
		count +=buffer[i];
	}
	return  count;
}

int get_giffies(int pid) 
{
	//TODO
	//Build the file name
	//Open file
	//read file content and store in a buffer
	//get_giffies(buffer)
	//return giffies

	char buff[1024], filename[1024];
	int fs, retval=0,tot_numbers=0;
	int list_of_numbers[500];

	sprintf(filename,"/proc/%d/stat", pid);  // convert the pid in to  command [ /proc/pid/stat ]
	//	printf("\n\r-->file name :%s\r\n", filename);

	if((fs=open(filename,O_RDONLY))==-1)
	{
	    printf("error in iopen a file :%s\r\n", filename);
	    exit(1);
	}

	retval = read(fs,buff,1024);

	buff[retval]='\0';

	//	printf("\n%s\n\r\t",buff);

	tot_numbers = parse_and_store(list_of_numbers, buff);

	return  tot_numbers;
}

int main(int argc , char *argv[])
{
    int giffies, i, j, count=0;
    int tot_pids = 0;
    int list_of_pids[MAX_PIDS][2];

    for (i = 0; i < argc-1 ; i++ )
    {
	list_of_pids[i][0]=atoi(argv[i+1]);
	printf("-->pid: %d\r\n", list_of_pids[i][0]);
    }

    tot_pids=argc-1;

    printf("-->total pid count :%d\n\r", tot_pids);

    for(j = 0 ;  ; j++ )
    {
	for( i = 0; i < tot_pids; i++)
	{
	    giffies = get_giffies(list_of_pids[i][0]);   
	    printf("-->%d:%d\r\n", list_of_pids[i][0], (giffies - list_of_pids[i][1]));
	    list_of_pids[i][1] = giffies;
	}

	sleep(1);
	printf("\r\n");
	count++;
    }		
}
