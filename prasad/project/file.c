#include"stdio.h"
#include"fcntl.h"
main()
{
int fd;
fd=create("myown.c",O_RDWR);
printf("fd==%d \n",fd);
close(fd);
}
