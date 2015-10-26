#include <stdio.h>
#include <fcntl.h>
#include "fop.h"
#include <sys/types.h>
#include <unistd.h>

main()
{
	int rfd=0, wfd=0,rret=0,len=10;
	char buff[100];

	rfd  = aopen("t1.txt",O_RDONLY,0);
	printf("fop_m=%d\n",rfd);

	wfd = aopen("t2.txt",O_CREAT|O_WRONLY,0777);
	printf("fop_m=%d\n",wfd);

	rret = aread(rfd,buff,len);
	buff[rret] = '\0';
	awrite(wfd,buff,rret);
	printf("%s\n",buff);

	//TODO: Do not use any i/o calls directly. Call only wrappers
	lseek(rfd,-10l,2);
	rret = aread(rfd,buff,len);
	buff[rret] = '\0';
	awrite(wfd,buff,rret);
	printf("%s\n",buff);

	aclose(rfd);
	aclose(wfd);
}
