#include "stdio.h"
#include "fop.h"
#include "fcntl.h"

main()
{
	int fd,fd1,w,r,l,len=10;
	char buff[20];

	printf("-->%d, %s, %s\n",__LINE__,__FUNCTION__,__FILE__);

	fd = aopen("t.txt",O_RDONLY,0);
	//TODO: what if file opening is failed ?

	fd1 = aopen("n.txt",O_CREAT|O_RDWR,0777);
	//TODO: what if file opening is failed ?

	r = aread(fd,buff,len);
	//TODO: what if file opening is failed ?

	buff[r] = '\0';

	printf("--->after r:%d\n",r);
	printf("--->after buff:%s\n",buff);

	w = awrite(fd1,buff,r);
	printf("--->after w:%d\n",w);

	l = alseek(fd,-10l,2);
	printf("--->after lsk:%d\n",l);

	r = aread(fd,buff,len);
	buff[r] = '\0';

	printf("--->after r:%d\n",r);
	printf("--->after buff:%s\n",buff);

	w = awrite(fd1,buff,r);
	printf("--->after w:%d\n",w);

	aclose(fd);
	aclose(fd1);
	printf("--->%d, %s, %s\n",__LINE__,__FUNCTION__,__FILE__);

}
