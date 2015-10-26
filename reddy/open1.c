#include <stdio.h>
#include <fcntl.h>
main()
{
char buff[100];
int fd = open("prasad.txt",O_RDONLY);
int r = read (fd, buff, 50);
printf("%s", buff);
printf("\n%d", r);
close (fd);

}
