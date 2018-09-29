#include "stdio.h"
#include "fcntl.h"
#include "fop.h"
main()
{
	int fd,fd1,r,w,lsk,l=10;
	char buff[20];
	
	printf("-->%d, %s, %s\n",__LINE__,__FUNCTION__,__FILE__);
	
	fd=aopen("t.txt",O_RDONLY,0);
	//TODO: what if file opening is failed ?

	fd1=aopen("r.txt",O_CREAT|O_RDWR,0777);
	//TODO: what if file opening is failed?

	r=aread(fd,buff,l);
	//TODO: what if file read is failed?

	buff[r]='\0';
	
	printf("--->after r:%d\n",r);
	printf("--->after buff:%s\n",buff);

	w=awrite(fd1,buff,r);
	printf("--->after w:%d\n",w);

	lsk=alseek(fd,-10l,2);
	printf("--->after lsk:%d\n",lsk);
	
	r=aread(fd,buff,l);
	buff[r]='\0';
	
	printf("--->after r:%d\n",r);
	printf("--->after buff:%s\n",buff);

	w=awrite(fd1,buff,r);
	printf("--->after w:%d\n",w);

	aclose(fd1);
	aclose(fd);
	printf("--->%d, %s, %s\n",__LINE__,__FUNCTION__,__FILE__);
}
