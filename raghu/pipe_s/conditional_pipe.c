#include <stdio.h>
#include <fcntl.h>
#define SIZE 30

main()
{
	int fd,pid;
	int i;
	char *msg1 = "AAAA";
	char *msg2 = "ZZZZ";
	char *msg3 = "BBBB";
	char *msg4 = "YYYY";
	char buff[SIZE];
	fd = open("raghu",O_RDWR);
	write(fd,msg1,SIZE);
	write(fd,msg3,SIZE);
	for(i=0;i<2;i++)
	{
		read(fd,buff,SIZE);

		if(strcmp(buff,msg1) == 0)
		{
			write(fd,msg2,SIZE);
		}
		
		if(strcmp(buff,msg3) == 0)
		{
			write(fd,msg4,SIZE);
		}
	}
	read(fd,buff,SIZE);
	printf("for %s the return value is %s\n",msg1,buff);
	read(fd,buff,SIZE);
	printf("for %s the return value is %s\n",msg3,buff);
}
