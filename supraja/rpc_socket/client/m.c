#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
#include"fcntl.h"
#include"fop.h"
#include"struct_replay.h"

int tcp_client_init(void);
//int client_sock_fd = -1;
int main()
{
 printf("%d %s \n ",__LINE__,__FILE__);

	int fd1,fd2,rval,len = 10,wval,lval;
	char buff[50];

	tcp_client_init();

	fd1 = aopen ("t.txt",O_RDONLY,0);
	if(fd1 == -1)
	{
		printf("fd1 open unsuccessfull\n");
	}
	fd2 = aopen ("r.txt",O_CREAT|O_RDWR,0777);
	if(fd2 == -1)
	{
		printf("fd2 open unsuccessfull\n");
	}
	while(1)
	{
	//	rval = aread(fd1,buff,len);
	//	buff[rval]='\0';
	//	printf("%s\n",buff);
	//	wval = awrite(fd2,buff,rval);
	//	lval = alseek(fd1,-10l,3);
		rval = aread(fd1,buff,len);
		buff[rval]='\0';
		printf("%s\n",buff);
		wval = awrite(fd2,buff,rval);
	    if(rval < len)
			break;

	}
	aclose(fd1);
	aclose(fd2);

	return 0;
}


#if 0
main()
{
	//init socket -> open socket, connect server
	//aopen
	//...
	//write
	//...
	//read
}

#endif
