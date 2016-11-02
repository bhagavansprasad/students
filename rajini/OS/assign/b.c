#include<stdio.h>
#include<fcntl.h>

main()
{	
	int r, fd, len=4;
		char buff[100];

	fd=open("t.txt", O_RDONLY, 0777);

	while(1)
	{
		r=read(fd, buff, len);
		buff[r]='\0';
		printf(" r : %d\n buff : %s\n ",r,buff);
		sleep(2);
		if(r<1)
			break;
	}
	close(fd);
}
