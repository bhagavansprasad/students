#include <stdio.h>
#include <fcntl.h>
int get_another_file();
main()
{
	int fd,r,l=6;
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
	get_another_file();
	close(fd);
}
