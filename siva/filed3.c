#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
main(int argc,char *argv[])
{
	int fd1,fd2,val;
	char buff[50];
	if(argc != 3)
	{
		perror("insufficient arguements\n");
		exit(1);
	}
	fd1=open(argv[1],O_RDONLY);
	if(fd1==-1)
	{
		perror("there is no file\n");
		exit(1);
	}
	fd2=creat(argv[2],O_RDWR);
	if(fd2==-1)
	{
		perror("failed to create file\n");
		exit(1);
	}
	while(1)
	{
		val=read(fd1,buff,3);
                printf("value sent to if statement\n");
	
		if(val > 0)
		{
                printf("writting is ready\n");
              write(fd2,buff,3);
                }
		else
                 {
                break;
		}

	}
close(fd1);
close(fd2);
}



