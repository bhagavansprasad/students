#include <stdio.h>
#include <fcntl.h>
int get_another_file()
{
	
	int fd,r,l=2;
	char buff[200];
	fd=open("t.txt",0,O_RDONLY);
	while(1)
	{
		r=read(fd,buff,l);
		buff[r]='\0';
		printf("r:%d\n  buff:%s\n",r,buff);
		sleep(1);
		if(r<l)
			break;

	}
	close(fd);
}
