#include "stdio.h"
#include "sys/types.h"
#include "fcntl.h"
#include "string.h"
#include "stdlib.h"

main()
{
	int fd1 = -1, r = -1;
	char buff[132];
	fd1 = open("student.db",O_RDONLY,0);

	read(fd1, buff, 188);
	buff[r] !='\0';

	close(fd1);
}
