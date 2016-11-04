#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"

struct student s1 = {10, "mounica"};
struct student s2 = {20, "Bharathi"};

int main()
{
	int ld,fd1,fd2,rval,wval;
	char buff[100];

	fd1=open("c.txt", O_APPEND|O_RDWR|O_CREAT, 0644);
	printf("fd1  :%d\n", fd1);

	wval = write(fd1, &s1, sizeof(struct student));
	printf("wval  :%d\n",wval);

	wval = write(fd1, &s2, sizeof(struct student));
	printf("wval  :%d\n",wval);

	return 0;
}
