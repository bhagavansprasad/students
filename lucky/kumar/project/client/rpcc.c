/********* CLIENT CODE ********/
#include <stdio.h>
#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "fop.h"
#include <stdlib.h>
#include <unistd.h>
#include "rpc.h"
#include "netc.h"

int main()
{
	init_netc_communication(SRVR_IP, SRVR_PORT);

	int r,len=10,fd=0,fd1=0,fd2=0;
	char buff[100];
	//int fd;
	fd=aopen("a.txt",0,O_RDONLY);
	if(fd < 0)
	{
		perror("open file is failed");
		printf("opening file is not sucessful\n");
		exit(1);
	}
	printf("opening file is sucessful\n");

	fd1=aopen("b.txt",O_CREAT|O_WRONLY,0777);
	if(fd1 < 0)
	{
		perror("creating file is failed");
		printf("creating file is not sucessful\n");
		exit(1);
	}
	printf("creating file is sucessful\n");

	fd2=aopen("c.txt",O_CREAT|O_WRONLY,0777);
	if(fd2 < 0)
	{
		perror("creating file is failed");
		printf("creating file is not sucessful\n");
		exit(1);
	}
	printf("creating file is sucessful\n");


	while(1)
	{
		r=aread(fd,buff,len);
		buff[r]='\0';
		awrite(fd1,buff,r);
		if(r<len)
			break;
	}

	lseek(fd,0,SEEK_SET);
	r=aread(fd,buff,len);
	buff[r]='\0';
	awrite(fd2,buff,r);

	lseek(fd,10,SEEK_CUR);
	r=aread(fd,buff,len);
	buff[r]='\0';
	awrite(fd2,buff,r);

	lseek(fd,-10,SEEK_END);
	r=aread(fd,buff,len);
	buff[r]='\0';
	awrite(fd2,buff,r);
	aclose(fd);
	aclose(fd1);
	aclose(fd2);
	return 0;
}

