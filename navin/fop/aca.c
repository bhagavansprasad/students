#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<unistd.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
	int fd, fd1,rd;
	char buff[10000];

	if(argc!=3)
	{  printf("Enter two files correctly");
		return 1;
	}

	fd=open(argv[1],O_RDWR);
	if(fd==-1)
	{
		printf(" Error in opening file"); 
		return 1;
	}
	else 
		printf(" \n file 1 successfully opened \n");

	fd1=open(argv[2],O_RDWR|O_CREAT,777);
	if(fd1==-1)
	{
		printf("\n Error in opening 2  file \n");
		return 1;
	}
	else 
		printf(" \n file 2 successfully opened \n ");

	rd=read(fd,buff,10000);

	if(rd==0)
		printf("\n noithing to write. File file is empty \n");
	else 
	   {
	   write(fd1,buff,rd);
	   printf(" copying completed :) \n\n");
	   }
		   

	close (fd);
	close (fd1);

	return 0;
}


