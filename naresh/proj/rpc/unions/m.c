#include "stdio.h"
#include "fcntl.h"
#include "defs.h"
#include "fop.h"
main()
{

	char buff[100];
	int fd, fd1,rd,w,l,t;


	fd = aopen("t.txt", O_RDONLY, 0);
	printf("in main fd1 is : %d\n",fd);

	fd1 = aopen("n.txt", O_RDWR|O_CREAT, 0777);
	printf("in main fd1 is : %d\n",fd1);

	rd = aread(fd, buff, MAX);

	
	buff[rd] = '\0';


	w = awrite(fd1, buff, rd);
	printf("--->After w :%d\n", w);

	l = alseek(fd, -10l, 2);

	rd = aread(fd, buff, MAX);
	buff[rd] = '\0';

	printf("-->After read :%d\n", rd);
	printf("-->After read buff   :%s\n", buff);

	w = awrite(fd1, buff, rd);
	printf("--->After write :%d\n", w);

	aclose(fd);
	aclose(fd1);
}

