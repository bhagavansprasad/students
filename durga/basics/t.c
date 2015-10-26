#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

main()
{
	//int fd = -1;
	int fd, r;
	char buf[100];
	printf("Hello\n");

	
	fd=open( "smaple.txt", O_RDONLY);
	//fd  =  open("t.txt", O_RDONLY);
}
