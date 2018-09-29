#include "stdio.h"
#include "fcntl.h"
#include <unistd.h>
#include "struct.h"

int main()
{
	int fd = 1, retval = 1;
	struct student sdata;

	fd = open("a.txt", O_RDONLY, 0744);
	printf("fd value is :%d\n", fd);

	while( retval > 0)
	{
		retval = read(fd, &sdata, sizeof(struct student));
		if(retval < sizeof(struct student))
			break;
		else
			printf("read retval is :%d\n", retval);
		student_records(&sdata);
	}

	return 0;
}

int student_records(struct student *p)
{
	printf("num : name-->%d, %s\n", p->num, p->name);

	return 0;
}
