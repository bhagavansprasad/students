#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <stdio.h>

main()
{
	char buff[100],fd;
	fd=open("s.txt",O_RDONLY);
	read(fd,buff,50);
	printf("%s\n",buff);
}
