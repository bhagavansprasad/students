#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>

main(int argc,char *argv[])
{
	int i,fd1,fd2,val;
	char b[100];
	if(argc<=2)
	{
		perror("insufficent arguments\n");
		exit(1);
	}
	fd1=open(argv[1],O_RDONLY);
	if(fd1==-1)
	{
		perror("can't open the source file of fd1\n");
		exit(1);
	}
	fd2=creat(argv[2],O_WRONLY);
	if(fd2==-1)
	{
		perror("cant open the destination filr of fd2\n");
		exit(1);
	}
	while(1)
	{
		val=read(fd1,b,10);
		b[val]='\0';
		if(val==0)
		{
			break;
		}
		for(i=0; b[i]!='\0';i++)
		{
			if(b[i]>=65 && b[i]<=91)
			{
				b[i]=b[i]+32;
			}
			if(b[i]>=97 && b[i]<=122);
			{
				b[i]=b[i]-32;
			}
		}
		write(fd2,b,val);
	}
}
