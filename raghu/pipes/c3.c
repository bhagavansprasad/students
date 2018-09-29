#include <stdio.h>
#include <fcntl.h>

main()
{
	int fd3,rd3;
	char *msg = "hey";
	char buff3[30];

	fd3 = open("raghu3",O_RDWR);
	rd3 = open("richie3",O_RDWR);

	write(fd3,msg,30);
	printf("the data send to the server %s\n",msg);

	read(rd3,buff3,30);
	printf("from the sever to 3 client %s\n",buff3);
}
