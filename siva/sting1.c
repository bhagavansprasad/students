#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
	int fd1,fd2,val,i;
	char buff[100];

	fd1 = open("es.txt",O_RDONLY);
	if(fd1==-1)
	{
		perror("file is not there\n");
	}
	fd2=creat("99r.txt",O_WRONLY);
	if(fd2==-1)
	{
		perror("file2 is not created\n");
		exit(0);
	}
	while(1)
	{
		val =  read(fd1,buff,1);
		buff[val]='\0';
		if(val==0)
		{
			break;
		}
		for(i=0;buff[i]!='\0';i++)
		{
			if(buff[i]>=65 && buff[i]<=91)
			{
				buff[i]=buff[i]+32;
			}
			if(buff[i]>=97 && buff[i]<=122)
			{
				buff[i]=buff[i]-32;
			}
		}	
		write(fd2,buff,val);
	}
}
