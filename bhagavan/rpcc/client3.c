#include<stdio.h>
#include<fcntl.h>
#include"afop2.h"

int main(int argc, char* argv[])
{
	int rfd,wfd,retval,wral,length=10;
	char buffer[512];

	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);

	rfd = a_open(argv[1],O_RDONLY,0644);
	wfd = a_open(argv[2],O_CREAT|O_RDWR,0644);

	while(1)
	{
		retval = a_read(rfd, buffer, length);
	//	buffer[retval]='\0';
		wral = a_write(wfd, buffer, retval);

		if(retval < length) 
			break;
	}

	a_close(rfd);
	a_close(wfd);
}
