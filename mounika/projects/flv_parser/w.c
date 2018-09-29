#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"

struct employee s1 = {1, "mounica"};
struct employee s2 = {2, "Bharathi"};
struct employee s3 = {3, "hema"};
struct employee s4 = {4, "Bindu"};

int main()
{
	int fd1,fd2,rval,wval;
	char buff[100];

	fd1=open("c.txt", O_APPEND|O_RDWR|O_CREAT, 0644);
	printf("fd1  :%d\n", fd1);
	int a=2;
	write(fd1,&a,sizeof(int));

	wval = write(fd1, &s1, sizeof(struct employee));
	printf("wval  :%d\n",wval);

	wval = write(fd1, &s2, sizeof(struct employee));
	printf("wval  :%d\n",wval);

	wval = write(fd1, &s3, sizeof(struct employee));
	printf("wval  :%d\n",wval);

	wval = write(fd1, &s4, sizeof(struct employee));
	printf("wval  :%d\n",wval);
	return 0;
}
