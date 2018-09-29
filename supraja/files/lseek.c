#include"stdio.h"
#include"unistd.h"
#include"fcntl.h"

int main()
{

	int rfd, wfd, rval,len = 10,wval,lval;
	char buff[50];


	rfd = open("t.txt", O_RDONLY, 0);

	wfd = open ("r.txt", O_CREAT|O_RDWR, 0777);

	//	while(1)
	//	{
	rval = read(rfd,buff,len);
	buff[rval]='\0';
	wval = write(wfd,buff,rval);
lval = lseek(rfd,-10l,2);
printf("----->lval:%d\n",lval);
	rval = read(rfd,buff,len);
	buff[rval]='\0';
	wval = write(wfd,buff,rval);
	//		if(rval < len)
	//			break;

//		}
	close(rfd);
	close(wfd);

	return 0;
}
