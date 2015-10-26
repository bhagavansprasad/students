#include"stdio.h"
#include "fcntl.h"
#include "defs.h"
#include "fop.h"
main()
{
	char buff[100];
	int rfd,wfd,read_retval,write_retval,lseek_retval;

	rfd=aopen("t.txt",O_RDONLY,0);
	wfd=aopen("d.txt",O_RDWR|O_CREAT,0777);

	read_retval=aread(rfd,buff,MAX);
	buff[read_retval]='\0';

	write_retval=awrite(wfd,buff,read_retval);
	lseek_retval=alseek(rfd,-MAX,2);

	read_retval=aread(rfd,buff,MAX);
	write_retval=awrite(wfd,buff,read_retval);

	aclose(rfd);
	aclose(wfd);
}
