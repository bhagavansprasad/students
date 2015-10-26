#include <stdio.h>
#include <fcntl.h>
#include "def.h"

main()
{
 	int i,fd,fd1;
	char *msg = "hi this is Richie";
	char *msg1 = "how are you";
	char *msg2 = "what are you doing";
	char *msg3 = "k chat you later";
	char buff[SIZE];
	
	fd = open("raghu",O_RDWR);
	fd1 = open("richie",O_RDWR);
	
	sleep(1);
	write(fd1,msg,SIZE);
	sleep(1);
	
		read(fd,buff,SIZE);
		printf("the read value is :-->%s\n",buff);
	
	write(fd1,msg1,SIZE);
	sleep(1);
	
		read(fd,buff,SIZE);
		printf("the read value is :-->%s\n",buff);
	
	write(fd1,msg2,SIZE);
	sleep(1);
	
		read(fd,buff,SIZE);
		printf("the read value is :-->%s\n",buff);
	
	write(fd1,msg3,SIZE);
	sleep(1);
	
		read(fd,buff,SIZE);
		printf("the read value is :-->%s\n",buff);
	
}
