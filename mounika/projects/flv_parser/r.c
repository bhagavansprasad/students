#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"


int dump_records(struct student *p)
{
	printf("No : Name --> %d, %s\n", p->num, p->name);

	return 0;
}

int main()
{
	int fd, retval = 1;
	char buff[100];
	struct student sdata;

	fd = open("c.txt", O_RDONLY, 0644);

	while(retval > 0)
	{
		retval = read(fd, &sdata, sizeof(struct student));
		printf("read retval :%d\n", retval);
		dump_records(&sdata);
	}


	return 0;
}
