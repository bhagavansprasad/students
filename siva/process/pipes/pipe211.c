#include<fcntl.h>
#include <stdio.h>
main()
{
	int fd,rd;
	char msg[11];
	fd=open("p.txt",O_RDONLY);
	lseek(fd,2,0);
	rd=read(fd,msg,11);
	printf("--->%d\n",rd);
	printf("---->%s\n",msg);
}
