#include "stdio.h"
#include "fop.h"
#include "fcntl.h"
main()
{
	int fd,fd1,w,r,len=10;
	char buff[20];
	
	fd = aopen("t.txt",O_RDONLY,0);
	printf("fd--->%d\n",fd);

	fd1 = aopen("n.txt",O_CREAT|O_RDWR,0777);
	printf("%d",fd1);

	r=aread(fd,buff,len);
	buff[r] = '\0';
	
	w=awrite(fd1,buff,r);
	
	alseek(fd,-10l,2);
	
	r = aread(fd,buff,len);
	buff[r] = '\0';
	printf("%s",buff);
	
	w=awrite(fd1,buff,r);
	aclose(fd);
	aclose(fd1);
}
