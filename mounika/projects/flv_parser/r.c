#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"


int dump_records(struct employee *p)
{
	printf("id : %d Name -->  %s\n", p->id, p->name);

	return 0;
}

int main()
{
	int fd, n,retval = 1;
	char buff[100];
		struct employee sdata;

	fd = open("c.txt", O_RDONLY, 0644);
	retval=read(fd,&n,sizeof(int));
	if(n==2)
	{
	while(1)
	{
		retval = read(fd, &sdata, sizeof(struct employee));
		printf("read retval :%d\n", retval);
		if(retval!=sizeof(struct employee))
		break;
		else
		dump_records(&sdata);
	}
	}
	return 0;
}
