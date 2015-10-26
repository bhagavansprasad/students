#include<stdio.h>
#include"fcntl.h"
#include <sys/types.h>
#include <sys/stat.h>

main()
{
int len =511;
char buff[512];
int fd =open ("t.txt",O_RDONLY);
int v =read(fd,buff,len);
 printf("%s",buff);
 close(fd);
}
