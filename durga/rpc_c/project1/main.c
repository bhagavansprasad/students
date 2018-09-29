#include<stdio.h>
#include <fcntl.h>
#include "fop.h"
#include "rpc_c.h"
#include <unistd.h>
main()
{
	int fd,fd1,r,w,ln = 10, s = 0;
	char buf[100];
	fd = aopen("a.c",O_RDONLY,0);
	printf("---->fd:%d", fd);
	fd1 = aopen("b.txt",O_CREAT|O_WRONLY,0777);
    while(1)
	{
	r = aread(fd, buf, ln);
	buf[r] = '\0';
	s+=r;
	w = awrite(fd1, buf, r);
	if(s==20)
	break;
}
 alseek(fd, -20l,2);
    while(1)
	{
	r = aread(fd, buf, ln);
	buf[r] = '\0';
	//s+=r;
	w = awrite(fd1, buf, r);
	if(r<ln)
	break;
}
aclose(fd);
aclose(fd1);
}

