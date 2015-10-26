#include <stdio.h>
#include "fcntl.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#pragma pack(1)
struct s1
{
	char name[124];
	int age;
	int class;
};

main()
{
	typedef struct s1 student;
	student stu_info[2], rdata[2];
	int fd,wretval=0,rretval=0,i;
	fd = open("student.db",O_RDWR,0);
	char buff[132];
	if(fd<0)
	{
		perror("file cant open bcoz");
		exit(1);
	}
	for(i=0;i<2;i++)
	{
		strcpy(stu_info[i].name, "devi");
		stu_info[i].age = 10;
		stu_info[i].class = 6;
		wretval = write(fd, &stu_info[i], sizeof(student));
		printf("s1.name-->%s\ns1.age-->%d\ns1.class-->%d\n", stu_info[i].name,
				stu_info[i].age, stu_info[i].class);
		printf("wretval-->%d\n",wretval);
	}
	lseek(fd, 0, 0);
	for(i=0;i<2;i++)
	{
		rretval = read(fd, &rdata[i], sizeof(student));
		if(rretval<0)
		{
			perror("file cant be read bcoz");
			exit(1);
		}
		printf("rdata.name-->%s\nrdata.age-->%d\nrdata.class-->%d\n", rdata[i].name,
				rdata[i].age, rdata[i].class);
		printf("rretval-->%d\n",rretval);
	}
	close(fd);
}
