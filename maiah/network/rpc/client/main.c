#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include "fop.h"
#include "arpc.h"
#include "rpcc_net.h"

int main()
{
	char srvr_ip[] = "127.0.0.1";
	int fd = -1;
	//int fd,fd1,r,w,ls,cl,l=10;
	//char buff[100];

	init_rpcc_network_comm(SRVR_PORT, srvr_ip);

	fd = aopen("venky.txt", O_RDONLY, 0);
	printf("-->fd value is : %d\n", fd);

#if 0
	fd1=aopen("b.txt",O_CREAT|O_RDWR,0777);
	printf("--->fd1 value is :%d\n",fd1);

	r=aread(fd,buff,l);
	buff[r]='\0';

	printf("%s\n",buff);

	w=awrite(fd1,buff,r);

	ls=alseek(fd,-20l,2);
	r=aread(fd,buff,20);
	buff[r]='\0';

	printf("%s\n",buff);

	w=awrite(fd1,buff,r);

	aclose(fd1);
	aclose(fd);
#endif
	return 0;
}
