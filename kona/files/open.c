#include<stdio.h>
#include<fcntl.h>
main()
{
	int fd,ln=12,r=0;
	char buf[100];
		fd=open("first.c",O_RDONLY);
		printf("%d",fd);
	while(1)
	{
		r=read(fd,buf,ln);
		printf("%s\n",buf);
		if(r<ln)
			break;
	}
	printf("-->end of the program");
	close(fd);
}

