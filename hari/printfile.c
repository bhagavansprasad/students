#include<stdio.h>
#include<fcntl.h>
main()
{
	int fd,ln=16,r=0,x;
	char buf[100];

	printf("sizeof buf :%d\n", sizeof(buf));

	fd=open("sample.txt",O_RDWR);
	while(1)
	{
		r = read (fd, buf, ln);
		buf[r]='\0';

		printf("%s\n", buf);
		x=r;

		if( x < ln)
			break;
	}

	printf("-->End of program\n");
	close(fd);
}


