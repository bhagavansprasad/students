#include <stdio.h>
#include <fcntl.h>
#include <error.h>
#include <stdlib.h>
main()
{
	int fd;
	int r, l =10;
	char buf[10];
	fd = open("/home/bhagavan/students/durga/project1", O_RDONLY,0777);
	printf("the fd return value is %d\n",fd);
	if(fd<0)
	{
		perror("error num:");
		exit(1);
	}
//	while(1)

	r = read(fd, buf, l );
	buf[r] = '\0';
	printf("%s", buf);
//	if(r<l)
//	break;
//	}

}
