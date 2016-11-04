#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
main()
{
	int rval,wval,rfd,wfd,r,len=10;
	char buff[50];
	rfd=aopen("s.txt",O_RDONLY,0);
	printf("\n read retval--->%d",rfd);
	wfd=aopen("d.txt",O_RDWR|O_CREAT,0777);
	printf("\n write retval---->%d",wfd);

		rval=aread(rfd,buff,len);
		buff[rval]='\0';
		wval=awrite(wfd,buff,rval);
		r=alseek(rfd,-10l,2);

		rval=aread(rfd,buff,r);
		buff[rval]='\0';
		wval=awrite(wfd,buff,rval);

	aclose(rfd);
	aclose(wfd);
}
