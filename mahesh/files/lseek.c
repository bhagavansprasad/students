#include <stdio.h>
#include "fcntl.h"
#include "sys/types.h" 
#include "sys/stat.h"
main ( )
{
char buff[512];
int fd1,rv,len=10;

fd1= open ("t.txt", O_RDONLY  ) ;


rv = read ( fd1, buff,len ) ;
buff[rv]='\0';
printf("%s\n",buff);
lseek(fd1,-11l,2);
rv = read ( fd1, buff,len ) ;
buff[rv]='\0';
printf("%s\n",buff);
close ( fd1) ;
}

