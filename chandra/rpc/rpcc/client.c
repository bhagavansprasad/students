#include <stdio.h>
//#include <sys/stat.h>
//#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "fop.h"
#include "reply_struct.h"

int tcp_client_init();

main()
{
	int  rfd, wfd, rretval, len=10;
	char buff[100];
	tcp_client_init();

	rfd = aopen("t1.txt", O_RDONLY, 0);
	printf("rfd val is : %d\n", rfd);

	wfd = aopen("t3.txt", O_CREAT| O_WRONLY|O_EXCL, 0777);
	printf("wfd val is : %d\n",wfd);

	//exit(1);
	while(1)
	{
		rretval = aread(rfd, buff, len);
		buff[rretval]='\0';
		awrite(wfd, buff, rretval);
		printf("%s\n", buff);

		//alseek(rfd, -10l, 2);
		//rretval = aread(rfd, buff, len);
		//buff[rretval]='\0';
		//awrite(wfd, buff, rretval);
		//printf("%s\n", buff);
		if(rretval < len)
			break;
	}

	aclose(rfd);
	aclose(wfd);

}
