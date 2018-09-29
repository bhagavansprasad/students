#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include "fop.h"
#include "rpc_c.h"
#include <unistd.h>
#include <errno.h>
#include "structer.h"
#include"server_structer.h"

void client_requst(void);


main()
{
	client_requst();
	int fd,fd1,r,w,ln = 10, s = 0;
	char buf[100];

	printf("--------> connection is established------->\n");
	fd = aopen("t.txt",O_RDONLY,0777);
	printf("---->open succes valu of fd :%d\n", fd);
	if(fd == -1)
	{
		printf("file open failed for t.txt");
		exit(1);
	}

	fd1 = aopen("t1.txt",O_CREAT|O_WRONLY,0777);
	printf("---->open and creating a file succes value of fd1 :%d\n", fd1);
	
	if(fd1 == -1)
	{
		printf("file open failed for a.txt");
		exit(1);
	}


	while(1)
	{
		r = aread(fd, buf, ln);
		buf[r] = '\0';
		printf("-----> buf :%s\n", buf);

		w = awrite(fd1, buf, r);


		//printf("-----> content in buff :%s\n", buf);
		if(r<ln)
			break;
	}

	aclose(fd);

	aclose(fd1);
}

