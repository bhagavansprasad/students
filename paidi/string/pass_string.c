#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
main(int argc, char *argv[] )
{
	int fd,i,w=0,nll=0,val=0,sum=0;
	char buff[100];
	fd=open("t.txt",O_RDONLY); 
	if(fd==-1)
	{
		printf("file is not open\n");
		exit(1);
	}

	val=read(fd,buff,80);
	buff[val]='\0';
	sum=sum+val;
//while(1)
//{
	for(i=0;i<val;i++)
	{
		if(buff[i]==' ')
			w++;
		if(buff[i]=='\n')
			nll++;
	}

	printf("ward-->=%d\n",w);
	printf("new line-->=%d\n",nll);
	printf("sum-->=%d\n",sum);
}


