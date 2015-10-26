#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
#include"fcntl.h"
#include"fop.h"
#include"struct_replay.h"

int tcp_client_init(void);

int main()
{
	printf("%d %s \n ",__LINE__,__FILE__);

	int rfd, wfd, rval,len = 10,wval,lval;
	char buff[50];

	tcp_client_init();

	rfd = aopen("t.txt", O_RDONLY, 0);
	printf("-->aopen rfd :%d\n", rfd);
	if(rfd == -1)
	{
		printf("rfd open unsuccessfull\n");
	}

	wfd = aopen ("r.txt", O_CREAT|O_RDWR, 0777);
	printf("-->aopen wfd :%d\n", wfd);
	if(wfd == -1)
	{
		printf("wfd open unsuccessfull\n");
	}

	//	while(1)
	//	{
	rval = aread(rfd,buff,len);
	buff[rval]='\0';
	printf("%s\n",buff);
	wval = awrite(wfd,buff,rval);
	lval = alseek(rfd,-10l,2);
	rval = aread(rfd,buff,len);
	buff[rval]='\0';
	printf("%s\n",buff);
	wval = awrite(wfd,buff,rval);
	//		if(rval < len)
	//			break;

	//	}
	aclose(rfd);
	aclose(wfd);

	return 0;
}
