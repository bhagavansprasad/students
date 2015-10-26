#include "stdio.h"
#include "stdlib.h"
#include <fcntl.h>
#include "unistd.h"
#define MAX_PIDS 1

int parse_and_store(int *arr ,char *buff);
int get_giffies(int pid);
int list_of_numbers[500];
void display(int *list_of_numbers,int n);
int total(int *arr);


int main(int argc , char *argv[])
{
	int giffies[100],i,j,count=0,temp[100];
	int tot_pids = 0,total=0;
	int list_of_pids[MAX_PIDS][2];
	
	for (i = 0; i < argc-1 ; i++ )
	{
		list_of_pids[i][0]=atoi(argv[i+1]);
		printf("\n\r%d", list_of_pids[i][0]);
		
	}
	tot_pids=argc-1;
	
	printf("\ntot-->%d\n\r",tot_pids);

/*	for ( i = 0; i < tot_pids; i++)
	{
		giffies = get_giffies(list_of_pids[i][0]);   

		//TODO
		
		list_of_pids[i][1] =  giffies;

		printf("-->pid[i]:%d -- giffies :%d\r\n", list_of_pids[i], giffies);
	}*/
	for(j = 0 ; j <=  MAX_PIDS ; j++ )
	{
		for( i = 0 ; i < tot_pids ;  i++)
		{
			giffies[i] = get_giffies(list_of_pids[i][0]);   
			
			printf("giffies[%d]-->%d\n\n\n",i,giffies[i]);

			
			if(count>= MAX_PIDS )
			{
				total=giffies[i]-temp[i];
				
				list_of_pids[i][1] =  total;
		        	
				printf("-->pid[%d]:%d--total-->:%d\r\n",i,list_of_pids[i][0],total);
			}
			else
			{
				temp[i]=giffies[i];
			}
		}
			sleep(1);
			count++;
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

	char buff[1024], buffer[1024];
	int fs,retval=0,tot_numbers=0;
	int list_of_numbers[500];

	sprintf(buffer,"/proc/%d/stat", pid);  
//	printf("\n\r-->file name :%s\r\n", buffer);

	if((fs=open(buffer,O_RDONLY))==-1)
	{
		printf("error in iopen a file");
		exit(1);
	}

	retval = read(fs,buff,1024);

	buff[retval]='\0';

//	printf("\n%s\n\r\t",buff);

	tot_numbers = parse_and_store(list_of_numbers, buff);

	return  tot_numbers;
}

int parse_and_store(int *list_of_numbera, char *buffer)
{
   char temp[1024];
   int i,j=0,k,count=0;
	
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

//	display(list_of_numbers,j);
	
	count=total(list_of_numbers);
	return  count;

}

int total(int *arr)

{
	int i,count=0;

	printf("\n\n\n");

	for(i=13;i<=16;i++)
	{
		count+=arr[i];

	}
	//	printf("count-->%d",count);

	return count;
}

void display(int *list_of_numbers,int n)
{
	int i; 
	for( i = 0; i<=n ; i++ )
	{
		printf(" arr[%d] -->%d\n\r",i,list_of_numbers[i]);
	}
}



