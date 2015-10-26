#include <stdio.h>
//#include <sys/stat.h>
//#include <sys/types.h>
#include <fcntl.h>
//#include <unistd.h>
#include "fop.h"

main()
{
	int  rfd, wfd, rretval, len=10;
	char buff[100];
	rfd = aopen("t1.txt", O_RDONLY, 0);
	wfd = aopen("t3.txt", O_CREAT| O_WRONLY|O_EXCL, 0777);

		rretval = aread(rfd, buff, len);
		buff[rretval]='\0';
		awrite(wfd, buff, rretval);

		alseek(rfd, -10l, 2);
		rretval = aread(rfd, buff, len);
		buff[rretval]='\0';
		awrite(wfd, buff, rretval);

		aclose(rfd);
		aclose(wfd);
}
