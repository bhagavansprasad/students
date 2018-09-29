#include <stdio.h>
#include "filop.h"
#include <fcntl.h>
#include<sys/stat.h>
main()
{
	int fd, fd1, r, w, ln=10;
	char buf[100];
	fd = aopen("prasad.c", O_RDONLY, 0);
	fd1 = aopen("b.txt", O_CREAT|O_RDWR,0777);
	while(1)
	{
		r = aread(fd, buf, ln);
		buf[r]='\0';
		printf("%s\n",buf);
        w = awrite(fd1, buf, r);
		printf("%s\n",buf);

		if(r<ln)
		break;
	}
	close(fd);
	close(fd1);
	}

