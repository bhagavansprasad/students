#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "fop.h"

int main()
{
	int rfd=0, wfd = 0, count=10, r;
	char buff[100];

	rfd = aopen("p.txt", 0, O_RDONLY);
	if(rfd < 0)
	{
		perror("open is failed");
		printf("errno :%d\n", errno);
		printf("open is not sucessful\n");
		exit(1);
	}

	wfd = aopen("k.txt",O_CREAT|O_WRONLY,0777);

	if(wfd < 0)
	{
		perror("error in creating file");
		printf("creating file is not sucessful\n");
		aclose(rfd);
		exit(1);
	}
	printf("creating file is sucessful\n");
	r=aread(rfd,buff,count);
	buff[r]='\0';

	awrite(wfd, buff, r);

	aclose(rfd);
	aclose(wfd);

	return 0;

}
