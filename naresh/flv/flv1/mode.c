#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "sys/types.h"
#include "string.h"
#include "defs.h"
main()
{
	int fd = -1,w = -1;
	fd = open("student.db", O_CREAT|O_RDWR,0);
	stu s1;
	strcpy(s1.name, "Naresh reddy");
	s1.age = 22;
	s1.class = 10;

	w = write(fd, &s1, sizeof(s1));

	close(fd);
	
}
