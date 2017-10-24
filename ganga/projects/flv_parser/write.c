#include "stdio.h"
#include "fcntl.h"
#include <unistd.h>
#include "struct.h"

struct student s1 = { 10, "ganga"};
struct student s2 = { 20, "ramesh"};

int main()
{
	int fd = 0, wretval = 0;

	fd = open("a.txt", O_APPEND | O_CREAT | O_RDWR, 0644);
	printf(" fd value is :%d\n", fd);

	wretval = write(fd, &s1, sizeof(struct student));
	printf(" write retval is :%d\n", wretval);

	wretval = write(fd, &s2, sizeof(struct student));
	printf(" write retval is :%d\n", wretval);

	return 0;
}
