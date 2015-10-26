#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
main()
{
 int i,fd;
 char buff[100];
 fd=("text.txt","O_RDONLY");
 i=read(int fd,char buff,10);
 buff[i]='\0';
 printf("%s",buff);
 printf("%d",i);
 close(fd);
}

