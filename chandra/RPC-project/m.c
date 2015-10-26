#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include<unistd.h>
#include <stdlib.h>
main()
{
	int rfd , wfd , t1, t2;
	char buff[100];
	int len=10, rretval=0, wretval=0;
	rfd = open( "t1.txt", O_RDONLY, 0777);
	if(rfd < 0)
	{
		perror("opening read failed");
		printf("reading rfd: %d\n", rfd);
		exit(1);
	}

	wfd = open( "t2.txt", O_CREAT | O_RDWR, 0777);

	printf("writing wfd: %d\n", wfd);
	if(wfd < 0)
	{
		perror("write failed");
		close(rfd);
		printf("writing wfd : %d\n", wfd);

	}

	while(1)
	{
		rretval = read(rfd, buff, len);
		wretval = write(wfd, buff, len);
		if(rretval < len)
			break;
	}

	//aread(t1.txt);
	//awrite(t2.txt);
	//aclose(t1.txt);
	//aclose(t2.txt);
}

