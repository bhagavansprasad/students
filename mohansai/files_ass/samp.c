#include "stdio.h"
#include "string.h"
#include "fcntl.h"
#include "stdlib.h"
#include <sys/types.h>
#include <sys/stat.h>

#define MAX 3
#define MAX1 MAX+MAX 
#define MAX2 2161 

//#define DEBUG 0 	

struct time
{
	char totstr[56];
	long int sumoftimes;
};
int n=0;


int get_time_from_string( char *src_str)
{
	int wcount=0,j=0,i=0,hours=0, minutes=0,seconds=0,mil_sec=0,total=0;
	char temp[10];

	for( i = 0 ; src_str[i] != '\0' && src_str[i] != '\n' ; i++ )
	{	
		if(src_str[i]!=':'  && src_str[i]!=' ' && src_str[i]!='.' )
		{
			temp[j++]=src_str[i];
		}
		else
		{
			wcount++;
			temp[j+1]='\0';
			
			if (wcount==1)
			{	
				hours=atoi(temp);
				printf("hours-->%d\n\r",hours);
			}
			else if	(wcount==2)
			{	
				minutes=atoi(temp);
				printf("minutes-->%d\n\r",minutes);
			}
			else if (wcount==3)
			{	
				seconds=atoi(temp);
				printf("seconds-->%d\n\r",seconds);
			}
			else if (wcount==4)
			{	
				mil_sec=atoi(temp);
				printf("milsec-->%d\n\r",mil_sec);
			}
			j=0;
			//ptime->total_time=ptime->hours + ptime->minutes + ptime->seconds +ptime->mil_sec;
			//printf("total:-%ld",ptime->total_time);	
		}

	}
	return total=hours*60*60*1000 + minutes*60*1000 + seconds*1000 + mil_sec;
	
	//ptime->total_time=ptime->hours*60*60*1000 + ptime->minutes*60*1000 +ptime->seconds*1000 +ptime->mil_sec;
	//printf("total-->%ld\n\r",ptime->total_time);	
}






void selection_sort(struct time *t3)
{
	struct time temp;
	int i,j;
	
	for( i = 0 ; i < MAX ; i++)
	{
		for( j = 0 ; j <= MAX-i	; j++)
		{
			if(t3[j].sumoftimes > t3[j+1].sumoftimes)
			{		
				temp =  t3[j];
				t3[j] =  t3[j+1];			
				t3[j+1] =  temp;
			}
		}
	}	
	/*	for( i = 0 ; i < MAX1 ; i++ )
		{
		printf("name:-  %s\t",t3[i].totstr);
		printf("\n\r");
		}*/
}

void combine(struct time *t3)
{
	struct time;
	int fd,fs,i;
	//printf("this is the cobine");

	creat("t3.txt",0777);

	fs = open("t3.txt",777);

	if (fs == -1)
	{	
		perror("error in open a file");
		exit(1);
	}
	for( i = 0 ; i < MAX1 ; i++ )
	{
		write(fs , t3[i].totstr, strlen(t3[i].totstr));
		write(fs , "\n", strlen("\n"));
		printf("-->arr1string stored in the structureof times :%s\r\n",t3[i].totstr);	
	}

	printf("\n\r");
	close(fs);	
}

void merge(struct time *t1, struct time *t2 , struct time *t3  )
{
	int i;

	for ( i = 0 ; i < MAX ; i++,n++ )
	{

		t3[n]=t1[i];

		//		printf("i==> %d n==> %d\n\r",i,n);
		//		printf("-->arr1 string stored in the structureof times :%s\r\n",t1[i].totstr);	
		//		printf("-->arr3 string stored in the structureof times :%s\r\n",t3[n].totstr);	
		//		printf("\n\r");
	}

	printf("\n\r");

	for( i=0;  i < MAX; i++,n++ )
	{

		t3[n]=t2[i];

		//		printf("i==> %d n==> %d\n\r",i,n);
		//		
		//		printf("-->arr2 string stored in the structureof times :%s\r\n",t2[i].totstr);	
		//		printf("-->arr3 string stored in the structureof times :%s\r\n",t3[n].totstr);	
		printf("\n\r");
	}
	/*	
		for( i=0;  i < 6 ; i++ )
		{

		printf("-->arr1string stored in the structureof times :%s\r\n",t3[i].totstr);	

		}*/
}

void parsestore(struct time *t1, char *buffer) 
{
	struct time;
	char temp[100],*str1;
	int hours,min,secs,milsecs,sum,i=0,j=0,k=0;
	//	printf("this is the loop\n\r");
	for( i = 0 ; buffer[i] != '\0' ; i++ )
	{
		if(buffer[i] != '\n' ) 
		{
			temp[k++]=buffer[i];
			//printf("charactrer temp[k] %c\n\r",temp[k]);
		}
		else
		{	
			temp[k]='\0';
			//printf("the total string temp-->%s\n\r\n",temp);	
			strcpy( t1[j].totstr , temp );
			
			sum = get_time_from_string( temp);
			
			t1[j].sumoftimes = sum;
			//printf("-->arr1 sum of times in :-%ld\r\n",t1[j].sumoftimes);	
			//printf("-->arr1string stored in the structureof times :%s\r\n",t1[j].totstr);	
			j++;
			k=0;

		}
	}
}
void parse_and_store(struct time *t2,char *buffer,int retval) 
{

	struct time;
	char temp[100],*str1;
	int hours,min,secs,milsecs,sum,i,j=0,k=0;

	//printf("this is the loop\n\r");
	for( i = 0 ; buffer[i] != '\0' ; i++ )
	{
		if(buffer[i] != '\n' ) 
		{
			temp[k++]=buffer[i];
		}
		else
		{
			temp[k]='\0';

			//printf("the total string temp-->%s\n\r\n",temp);	
			strcpy( t2[j].totstr , temp );

			sum = get_time_from_string( temp);
			t2[j].sumoftimes = sum;

			//printf("-->arr2 sum of times in :-%ld\r\n",t2[j].sumoftimes);	
			//printf("-->arr2 string stored in the structureof times :%s\r\n",t2[j].totstr);	
			j++;
			k=0;
		}
	}

}

main(int argc, char *argv[])
{
	struct time t1[MAX], t2[MAX], t3[MAX+MAX];
	int i=0;
	int fd,fs,retval=0,retval1=0;
	char buffer1[1000],buffer2[1000];

	if(argc < 3)
	{
		perror("the is no sufficient argumenrs");
		exit(1);
	}
	if((fd=open(argv[1], O_RDONLY, 0)) == -1) 
	{	
		perror("error in open a file");
		exit(1);
	}
	while(1)
	{
		retval=read(fd, buffer1, 500);
		//	printf("buffer1-->%s\r\n",buffer1);
		buffer1[retval+1]='\0';

		parsestore(t1,buffer1); 
		//printf("this is loop retval %d",retval);	
		if(retval<100)
		{
			//	printf("first file reading finished\n\r");
			close(fd);
			break;
		}	
	}

	//printf("hellow");

	if((fs=open(argv[2], O_RDONLY, 0)) == -1) 
	{	
		perror("error in open a file");
		exit(1);
	}
	while(1)
	{
		retval1=read(fs,buffer2,500);

		//printf("buffer2-->%s\r\n",buffer2);

		buffer2[retval1+1]='\0';

		parse_and_store (t2,buffer2,retval1); 

		if(retval1<100)
		{
			//printf("the second file reading finished\n\r");
			break;
		}	
	}
	merge(t1,t2,t3);	

	for( i = 0 ; i < 6; i++ )
	{
		printf("-->arr3 string stored in the structureof times :%s\r\n",t3[i].totstr);	
	}	
	printf("\n\r");	
	selection_sort(t3);

	combine(t3);

	close(fd);
	close(fs);
}
