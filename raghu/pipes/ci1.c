#include <stdio.h>
#include <fcntl.h>

main()
{
	int fd1,rd1,ret;
	char *msg = "hi";
	char cbuff1[30];

	fd1 = open("raghu1",O_RDWR);
	rd1 = open("richie1",O_RDWR);
	printf("open value is : %d\n",rd1);

	write(fd1,msg,30);
	printf("the data send to the server %s\n",msg);
	
	ret = read(rd1,cbuff1,30);
	cbuff1[ret]='\0';
	printf("ret value is : %d\n",ret);
	printf("from the server %s\n",cbuff1);

}
