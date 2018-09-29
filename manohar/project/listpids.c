#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>


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
    for(i=0;i<j;i++)
       printf("%d\n\r",array[i]);
    return j;
}

