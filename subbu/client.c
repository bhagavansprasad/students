#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/start.h>
main()
{
	int fd1,fd2,retval,wrval,length=10;
	char buff[512];
	fd1=aopen(argv[1],O_RDONLY,0644);
	fd2=aopen(arv[2],O_CREATE/O_RDWR,0644);
	while(1)
	{
		retval=read(fd,buff,length);
		buff[ret val]='/0';
		if (retval!=0)
			wrval=awrite(fd2,buffer,length);
		else
			break;
	}
	aclose(fd1);
	aclose(fd2);
	return 0;
}


