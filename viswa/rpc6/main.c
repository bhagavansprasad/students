#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "afun.h"
main()
{
	int rfd, wfd, retv_read, retv_write, len = 10;
	char buff[100];
	rfd = aopen("t.txt",O_RDONLY,0);
	printf("rfd_=%d\n",rfd);
	wfd = aopen("t2.txt",O_CREAT|O_WRONLY|O_TRUNC,0777);
	while(1)
	{
		retv_read = aread( rfd, buff, len);
		buff[retv_read]='\0';
		retv_write = awrite(wfd,buff,retv_read);
		printf("retv_read =%s\n",buff);
		printf("retv_write =%d\n",retv_write);
		if(retv_read < len)
			break;
	}
	aclose(wfd);
	aclose(rfd);
}

