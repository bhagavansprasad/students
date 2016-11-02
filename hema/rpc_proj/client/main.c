#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
main()
{
	int rval,wval,rfd,wfd,r,len=10;
	char buff[50];

	printf("-->C,%d,%s,%s\n", __LINE__, __FUNCTION__, __FILE__);

	init_rpc_communication();

	rfd = aopen("t.txt",O_RDONLY,0);
	printf("-->C: aopen success for s.txt rfd :%d\n\n", rfd);

	wfd=aopen("d1.txt",O_RDWR|O_CREAT,0777);
	printf("-->C: aopen success for d.txt wfd :%d\n\n", wfd);

	rval=aread(rfd,buff,len);
	buff[rval]='\0';
	printf("-->C: aread success for fd :%d, retval :%d\n\n", rfd, rval);

	wval=awrite(wfd,buff,rval);
	printf("-->C: awrite success for fd :%d, retval :%d\n\n", wfd, wval);

	r=alseek(rfd,-10l,2);
	printf("-->C: alseek success for fd :%d, retval :%d\n\n", rfd, r);

	rval=aread(rfd,buff,r);
	buff[rval]='\0';
	wval=awrite(wfd,buff,rval);

	aclose(wfd);
	printf("-->C:aclose success for wfd:%d\n\n",wfd);
    aclose(rfd);
	printf("-->C:aclose success for rfd:%d\n\n",rfd);

}
