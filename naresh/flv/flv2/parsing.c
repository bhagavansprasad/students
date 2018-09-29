#include "stdio.h"
#include "sys/types.h"
#include "fcntl.h"
#include "string.h"
#include "stdlib.h"
#include "defs.h"

main()
{
	stu s1;
	stu2 s2;
	int fd1 = -1, r = -1;
	int i;
	int retval;
	fd1 = open("student23.db",O_RDONLY,0);

	read(fd1, &i, sizeof(i));
	if(i == 1)
	{
		retval = read(fd1, &s1, sizeof(s1));
		printf("name :%s\n age :%d\n class :%d\n",s1.name, s1.age, s1.class);
	}
	else if(i == 2)
	{
		retval = read(fd1, &s2, sizeof(s2));
		printf("name :%s\n grade :%c\n marks :%d\n age :%d\n class :%d\n",s2.name, s2.grade, s2.marks, s2.age, s2.class);
	}
	close(fd1);
}
