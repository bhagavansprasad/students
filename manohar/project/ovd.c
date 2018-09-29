#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include"defs.h"




int aatoi(char *str)

{
	int r,sum=0;
	for( ; *str!='\0';str++)
	{
		if(*str >= '0'&& *str <='9')
		{
			r=*str-'0';
			sum=sum*10+r;
		}
	}
	return sum;
}

int listpids(int *array)
{

	int fp;
	int i,j,k,a,giff;
	char buff[1000],temp[1000];
	system("ps -A -o pid >txt");
	fp=open("txt",O_RDONLY);
	if(fp==-1)
		printf("error in opening file");
	a=read(fp,buff,1000);
	buff[a]='\0';
	close(fp);
	for(i = 0; buff[i] != '\n'; i++);
	i++;
	for(j=0;buff[i];i++)
	{ 
		for(k=0;buff[i]!='\n';i++)
			temp[k++]=buff[i];
		temp[k]='\0';
		array[j]=aatoi(temp);
		j++;
	}
	//for(i=0;i<j;i++)
	//	printf("%d .... pids\n\r",array[i]);
	return j;
}

int giffies(int pid)
{
	FILE *fp;
	int a,k,sum=0,count=0,i,j;
	char temp[1024],buff[1024],arr[1024];
	sprintf(temp,"/proc/%d/stat",pid);
	fp = fopen(temp, "r");
	if(fp == NULL)
	{
		perror("file open failed");
		exit(0);
	}
	a= fread(buff,1,1512,fp);
	for(i=0;count<13;i++)  
	{
		if(buff[i] ==' ')
			count++;
	}
	for(j=0;j<4;j++)
	{
		k=0;
		for(;buff[i]!=' ';i++)
		{
			arr[k]=buff[i];
			k++;
		}
		i++;
		arr[k]='\0';
		sum = sum + atoi(arr);
	}
	return sum;
}

void ovd(int writefd)
{
	struct data x;
	int arr[1000];
	int i,noofpids,retval,a;
	//printf("this is  the ovd process");
	noofpids = listpids(arr);
	
   for(i=0;i<noofpids;i++)
	{

		//retval = giffies(arr[i]);
		//printf("\r\n\n\n\npids...%d\n\r",arr[i]);
		//printf("processno...%d\n\rgiffies...%d\n\r",i,retval);          

		a=(x.giff = giffies(arr[i]));
		if(a == -1)
		continue;
		
		x.pid = arr[i];
                //printf("\r\nprocessno...%d\n\rgiffies...%d\n\r",x.pid,x.giff);        
		
		retval = write(writefd,&x,sizeof(struct data));
		if(retval == -1)
		{
			perror("write to fail");
			//	exit(0);
		}

		//printf("pid...%d\n\rgiffies...%d\n\r",x.pid,x.giff);        
                //printf("total process%d\n\r",i);
		//printf("write is sucess\n\n\n");

	}
}

