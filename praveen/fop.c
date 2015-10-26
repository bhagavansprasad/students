#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include "hfop1.h"

main()
{
	int fd = 0,fwrt = 0,retval = 0,t,s1 = 0,len = 10;
	char buff[100];
	fd = aopen("t.txt",O_RDONLY,0);
	printf("%d\n",fd);
	fwrt = aopen("t1.txt",O_CREAT|O_WRONLY,0777);
	printf("%d\n",fwrt);
	while(1)
	{
		retval = aread(fd,buff,len);
		buff[retval] = '\0';
		printf("%d\n",retval);

		s1 = awrite(fwrt,buff,retval);
			if(retval < len)
			break;
	}
	aclose(fd);
	aclose(fwrt);
}

