#include "stdio.h"
#include "fcntl.h"
#include "errno.h"
#include "stdlib.h"
#include "string.h"
#include "rpc_netc.h"
#include "fop.h"
#include "structure.h"
int main()
{
	init_netc_communication(SRVR_IP, SRVR_PORT);

	int rfd=0, wfd=0, lfd=0, rretval = 0, wretval = 0, len = 20;
	char buff[200];

	rfd = aopen("x.txt", O_RDONLY, 0);
	if(rfd < 0)
	{
		perror("open failed because");
		printf("open error         =  %d\n",errno);
		exit(1);
	}
	printf("open is success to read the file a.txt....\n");

	wfd = aopen("b.txt", O_CREAT|O_RDWR, 0777);
	if(wfd < 0)
	{
		perror("open failed because");
		printf("open error         =  %d\n", errno);
		aclose(rfd);
		exit(1);
	}
	printf("open is success to write in file b.txt....\n");

	lfd = aopen("c.txt", O_CREAT|O_RDWR, 0777);
	if(lfd<0)
	{
		perror("open failed because");
		printf("open error         =  %d", errno);
		aclose(rfd);
		aclose(wfd);
		exit(1);
	}
	printf("open is success to write in file c.txt....\n");

	while(1)
	{
		rretval = aread(rfd, buff, len);
		if(rretval < 0)
		{
			perror("read is failed because");
			printf("read error            =  %d", errno);
			aclose(rfd);
			exit(1);
		}

		buff[rretval]='\0';

		wretval = awrite(wfd,buff,rretval);
		if (wretval < 0)
		{
			perror("writing is failed because");
			printf("write error              =  %d", errno);
			aclose(wfd);
			exit(1);
		}
		if(rretval < len)
			break;
	}

	alseek(rfd, 0, SEEK_SET);

	rretval = aread(rfd, buff, len);
	buff[rretval]='\0';

	awrite(lfd,buff,rretval);

	alseek(rfd, -20, SEEK_END);
	rretval = aread(rfd, buff, len);
	buff[rretval]='\0';

	awrite(lfd,buff,rretval);

	aclose(lfd);
	aclose(wfd);
	aclose(rfd);
	return 0;
}
