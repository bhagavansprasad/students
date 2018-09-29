#include "stdio.h"
#include "stdlib.h"
#include <fcntl.h>
#include "unistd.h"
#define MAX_PIDS 10

int parse_and_store(int *arr ,char *buff);

int get_giffies(int pid);

int list_of_pids[MAX_PIDS];

int list_of_numbers[500];

void display(int *list_of_numbers,int *n);

int total(int *arr);

int main(int argc , char *argv[])
{
	int giffies,i,d=0;
	int tot_pids = 0;
	int list_of_pids[20];
	
	for (i = 0; i<argc-1 ; i++ )
	{
		list_of_pids[i]=atoi(argv[i+1]);
		
		printf("\n\r%d",list_of_pids[i]);
	}
	
	tot_pids=argc-1;
	
	printf("\ntot-->%d\n\r",tot_pids);


	for (i = 0; i < tot_pids; i++)
	{

		giffies = get_giffies(list_of_pids[i]);   

		printf("-->pid[i]:%d -- giffies :%d\r\n", list_of_pids[i], giffies);
	}
}



int get_giffies(int pid) 
{
	//TODO
	//Build the file name
	//Open file
	//read file content and store in a buffer
	//get_giffies(buffer)
	//return giffies

	char buff[1024],buffer[1024];

	int fs,retval=0,tot_numbers=0;

	int list_of_numbers[500];


	sprintf(buffer,"/proc/%d/stat", pid);  

	printf("-->file name :%s\r\n", buffer);

	if((fs=open(buffer,O_RDONLY))==-1)
	{
		printf("error in iopen a file");
		exit(1);

	}

	retval = read(fs,buff,1024);

	buff[retval]='\0';

	printf("\n%s\n\r\t",buff);

	tot_numbers = parse_and_store(list_of_numbers, buff);

	return  tot_numbers;
}


int parse_and_store(int *list_of_numbera, char *buffer)
{
   char temp[1024];
   int temp1;
   int i,j=0,k,count=0,m=0;
	
	for( i = 0,k = 0; buffer[i] != '\0'; i++,k++ )
  	{
		if(buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\r')
		{
  			 temp[k]=buffer[i];
  	    }
  	    else
  		{
  			 for( ; buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] =='\r' ;i++);
  			 temp[k]='\0';

 			  if(k != 0)
		      {
  				list_of_numbers[j] = atoi(temp);
			    j++;
 			  }
  				
				k = -1;
  			    i--;
  		}
	}

//	display (list_of_numbers,j);
	
	count=total(list_of_numbers);

return  count;
}
/*	for( i = 0 ; i <= j ; i++)
	{
		printf("arr[%d]-->%d \n",i,list_of_numbers[i]);
	}*/
//}


/*void display(int *list_of_numbers,int *n)
{
	int i; 
	for( i = 0; i<=n ; i++ )
	{
		printf(" arr[%d] -->%d\n\r",i,list_of_numbers[i]);
	}
}*/


int total(int *arr)
{
	int i,count=0;

	printf("\n\n\n");

	for(i=13;i<=16;i++)
	{
		count+=arr[i];

	}
	printf("count-->%d",count);

return count;
}


