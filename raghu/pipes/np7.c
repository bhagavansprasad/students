#include <stdio.h>
#include <fcntl.h>
#include "def.h"

main()
{
	int i,fd,fd1;
	char *msg="hi this is raghu";
	char *msg1="fine, what about you";
	char *msg2="doing project";
	char *msg3="k bye";
	char buff1[SIZE];

	fd = open("raghu",O_RDWR);
	fd1 = open("richie",O_RDWR);

	write(fd,msg,SIZE);
	
		read(fd1,buff1,SIZE);
		printf("the read value is :--> %s\n",buff1);
sleep(1);	
	write(fd,msg1,SIZE);
	
		read(fd1,buff1,SIZE);
		printf("the read value is :--> %s\n",buff1);
	
sleep(1);	
	write(fd,msg2,SIZE);
	
		read(fd1,buff1,SIZE);
		printf("the read value is :--> %s\n",buff1);
	
sleep(1);	
	write(fd,msg3,SIZE);
	
		read(fd1,buff1,SIZE);
		printf("the read value is :--> %s\n",buff1);
}
