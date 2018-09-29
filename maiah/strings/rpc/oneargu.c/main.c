#include <stdio.h>
#include <fcntl.h>
#include "fop.h"
main()
{
	//int rpcc_init_net(int port,char *p);
	int fd,fd1,r,w,ls,cl,l=10;
	char buff[100];

	printf("-->%d, %s, %s\n",__LINE__,__FUNCTION__,__FILE__);

	fd=aopen("venky.txt",O_RDONLY,0);
	//TODO: what is file opening is falied ?

	fd1=aopen("b.txt",O_CREAT|O_RDWR,0777);
	//TODO: what is file opening is falied ?

	r=aread(fd,buff,l);
	//TODO: what is file opening is failed ?
    
	buff[r]='\0';

	printf("--->after r:%d\n",r);
	printf("--->after 1st buff:%s\n",buff);

	w=awrite(fd1,buff,r);
	printf("--->after w:%d\n",w);

	ls=alseek(fd,-20l,2);
	printf("--->after ls:%d\n",ls);

	r=aread(fd,buff,20);
	buff[r]='\0';

	printf("--->after r:%d\n",r);
	printf("--->after 2nd buff:%s\n",buff);

	w=awrite(fd1,buff,r);
	printf("--->after w:%d\n",w);

	aclose(fd1);
	aclose(fd);
	printf("--->%d, %s, %s\n",__LINE__,__FUNCTION__,__FILE__);
}
