#include <stdio.h>
#include <fcntl.h>
#include "fop.h"
#include <sys/types.h>
#include <unistd.h>
void tcp_client_init();
main()
{
	int rfd=0, wfd=0,rret=0,len=10;
	char buff[100];

	tcp_client_init();

	rfd  = aopen("/home/bhagavan/students/raghu/rpc/rpcs/z.txt", O_RDONLY, 0);
//	printf("in main fd is: =%d\n",rfd);

	wfd = aopen("t9.txt", O_CREAT|O_RDWR, 0777);
//	printf("in main fd is =%d\n",wfd);

	while(1)
	{
		rret = aread(rfd,buff,len);
		buff[rret] = '\0';
		printf("in main buff:%s\n",buff);
		awrite(wfd,buff,rret);
		printf("rret is : %d\n,len is : %d\n",rret,len);
		if(rret<len)
			break;
		//	lseek(rfd,-10l,2);
		//	rret = aread(rfd,buff,len);
		//	buff[rret] = '\0';
		//	awrite(wfd,buff,rret);
		//	printf("%s\n",buff);
	}
	aclose(rfd);
	aclose(wfd);
}
