#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include <stdlib.h>
#include <errno.h>

void main()
{
	char buff[100];
	int rfd, wfd, i = 0;
	int rretval = 0;
	int wretval = 0;

	rfd = open("1t.txt", 0, O_RDONLY);
	if (rfd < 0)
	{
		perror("-->Opening a file for read failed ");
		printf("-->Open failed for writing rfd :%d\n", rfd);
		exit(1);
	}

	//wfd = open("t2.txt", 0777, O_EXCL | O_CREAT | O_RDWR );
	wfd = open("t2.txt", O_EXCL | O_CREAT | O_RDWR, 0777);
	printf("-->wfd :%d\n", wfd);
	if (wfd < 0)
	{
		perror("-->Opening a file for write failed ");
		close(rfd);
		printf("-->Open failed for writing wfd :%d\n", wfd);
		exit(1);
	}

	printf("-->wfd :%d\n", wfd);
	for(i=0; 1 ;i++)
	{
		rretval = read(rfd, buff, 10);
		buff[rretval] = '\0';
		printf("-->read retval :%d\n", rretval);
		printf("-->buffer :%s\n", buff);

		printf("-->wfd :%d\n", wfd);
		wretval = write(wfd, buff, rretval);
		printf("-->wretval :%d\n", wretval);
		if (wretval < 0 )
		{
			perror("-->Write failed");
			printf("-->wretval :%d\n", wretval);
			close(rfd);
			close(wfd);
			exit(1);
		}
		printf("-->write retval :%d\n", wretval);

		if(rretval < 10)
			break;
	}
}
