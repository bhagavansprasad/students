#include "stdio.h"
#include "fop.h"
#include "fcntl.h"
main()
{
	int fd,r,fd1,len=9,w,l;
	char buff[20];
	fd = aopen("t.txt",O_RDONLY,0);
	fd1 = aopen("n.txt",O_CREAT|O_RDWR,0644);
	r = aread(fd,buff,len);
	buff[r] = '\0';
	printf("%s",buff);
	w=awrite(fd1,buff,r);
    alseek(fd,-9l,2);
	r = aread(fd,buff,len);
	buff[r] = '\0';
	printf("%s",buff);
	w=awrite(fd1,buff,r);
	aclose(fd);
	aclose(fd1);
}
