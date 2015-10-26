#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
main()
{
	char  buff[1000];
	int retval=0;
	int fd =-1;
	fd = open("r.txt",O_RDONLY);
	if(fd==-1)
	{
		perror("file doesnt exist\n");
	}
	retval = read(fd, buff,sizeof(buff));
	printf("retval-->=%d\n",retval);
	buff[retval]='\0';
	printf("%s\n",buff);
}

