/********* CLIENT CODE ********/
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include "fop.h"
#include <stdlib.h>
#include "rpc.h"
#include "netc.h"

int main()
{
	init_netc_communication(SRVR_IP, SRVR_PORT);
	int r, len = 10,rfd=0,wfd=0,lfd=0,wretval = 0;
	char buff[100];
	rfd = aopen("a.txt",O_RDONLY,0);
	if(rfd < 0)
	{
		perror("open file is failed");
		printf("opening file is not sucessful\n");
		exit(1);
	}
	printf("opening file is sucessful\n");

	wfd = aopen("c.txt",O_CREAT|O_RDWR,0777);
	if(wfd < 0)
	{
		perror("creating file is failed");
		printf("creating file is not sucessful\n");
		exit(1);
	}
	printf("creating file is sucessful\n");

	lfd = aopen("d.txt",O_CREAT|O_RDWR,0777);
	if(lfd < 0)
	{
		perror("creating file is failed");
		printf("creating file is not sucessful\n");
		exit(1);
	}
	printf("creating file is sucessful\n");


	while(1)
	{
		r=aread(rfd,buff,len);
		buff[r]='\0';
		wretval = awrite(wfd,buff,r);
		if(wretval < 0)
		{
		perror("writing is failed because ");
		}

		if(r<len)
			break;
	}

	lseek(rfd,0,SEEK_SET);
	r=aread(rfd,buff,len);
	buff[r]='\0';
	awrite(lfd,buff,r);

	lseek(rfd,10,SEEK_CUR);
	r=aread(rfd,buff,len);
	buff[r]='\0';
	awrite(lfd,buff,r);

	lseek(rfd,-10,SEEK_END);
	r=aread(rfd,buff,len);
	buff[r]='\0';
	awrite(lfd,buff,r);
	
	aclose(lfd);
	aclose(wfd);
	aclose(rfd);
	return 0;
}

