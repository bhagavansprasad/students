#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "sys/types.h"
#include "string.h"
#include "defs.h"
#include "errno.h"
#include "unistd.h"
main()
{
	int fd = 0,w = -1;
	//int i = 1;
	int i = 2;
	int retval ;
	fd = open("student23.db",O_CREAT|O_WRONLY, 0777);
	if(fd < 0)
	{
		printf("failed :%d errno :%d\n",fd, errno);
		perror("open failed because");
	}
	stu s1;
	strcpy(s1.name, "Naresh reddy");
	s1.age = 22;
	s1.class = 10;
	
	stu2 s2;
	strcpy(s2.name, "sunny");
	s2.grade = 'A';
	s2.marks = 99;
	s2.age = 23;
	s2.class = 10;

	w = write(fd, &i, sizeof(i));
	if(i == 1)
	{
		retval = write(fd, &s1, sizeof(s1));
		printf("retval %d size :%d\n",retval, sizeof(stu));
	}
	else if(i == 2)
	{
		retval = write(fd, &s2,sizeof(s2));
		printf("retval %d size :%d\n",retval, sizeof(stu2));
	}

	close(fd);
	
}
