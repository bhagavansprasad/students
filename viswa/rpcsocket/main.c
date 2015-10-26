#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include"sys/types.h"
#include"sys/socket.h"
#include "afun.h"
#include <stdlib.h>

main()
{
	int rfd,wfd,retv_read=0,retv_write=0,len=10;
	char buff[100];

	socket_init();

	rfd = aopen("t.txt",O_RDONLY,0);
	printf("rfd is : %d\n",rfd);	
	if(rfd == -1)
	{
		printf("error no is : %d\n",errno);
		perror("error is : ");
		exit(1);
	}

	wfd = aopen("t2.txt",O_CREAT|O_RDWR,0777);
	if(wfd == -1)
	{
		perror("client is failed to open2 and connect a fail-->\n");
		aclose(rfd);
		exit(1);
	}

	while(1)
	{
		retv_read = aread(rfd, buff , len);
		buff[retv_read] = '\0';
		printf("buff:--->=%s\n",buff);

		retv_write = awrite(wfd,buff ,retv_read);

		printf("retv_write:->%d-->=",retv_write);

		if(retv_read < len)
			break;
	}
	aclose(wfd);
	aclose(rfd);
}
