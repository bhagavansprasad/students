#include <stdio.h>
main()
{
char buffer[100];
int fd=0;
fd=open("t.txd",0,O_RDONLY);
read(fd,buff,15)
printf("%s",buff);
close(fd);
}
