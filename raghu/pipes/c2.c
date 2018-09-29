#include <stdio.h>
#include <fcntl.h>

main()
{
	int fd2,rd2;

	char *msg = "hello";
	char buff2[30];

	fd2 = open("raghu2",O_RDWR);
	rd2 = open("richie2",O_RDWR);

	write(fd2,msg,30);
	printf("the data send to the server %s\n",msg);

	read(rd2,buff2,30);
	printf("from the server to 2 :%s\n",buff2);

}
