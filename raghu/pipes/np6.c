#include <stdio.h>
#include <fcntl.h>
#include "def.h"

main()
{
	int fd1,fd2,pid;
	int rretval;
	fd1 = open("raghu",O_RDWR);
	fd2 = open("richie",O_RDWR);
	char *msg1 = "the ";
	char *msg2 = "them ";
	char *msg3 = "they ";
	char *msg4 = "that ";
	char *msg5 = "then ";
	char *msg6 = "thus ";
	
	char buff1[SIZE];
	char buff2[SIZE];
	
	pid = fork();

	if(pid == 0)
	{
		write(fd1,msg1,SIZE);
		write(fd1,msg2,SIZE);
		
		rretval=read(fd2,buff2,SIZE);
		printf("from the parent %s\n",buff2);
		buff2[rretval]='\0';
		
		write(fd1,msg3,SIZE);
		write(fd1,msg4,SIZE);
		
		read(fd2,buff2,SIZE);
		printf("from the parent %s\n",buff2);
	}
	else
	{
		write(fd2,msg5,SIZE);
		write(fd2,msg6,SIZE);
		
		read(fd1,buff1,SIZE);
		printf("from the child %s\n",buff1);
		read(fd1,buff1,SIZE);
		printf("from the child %s\n",buff1);
		read(fd1,buff1,SIZE);
		printf("from the child %s\n",buff1);
		read(fd1,buff1,SIZE);
		printf("from the child %s\n",buff1);

	}

}
