#include <stdio.h>
#include "fcntl.h"
#include "sys/types.h" 
#include "sys/stat.h"
main ( )
{
	char buff[512];
	int fd1,rv,len=20;

	fd1= open ("t.txt", O_RDONLY  ) ;
	rv = read ( fd1, buff,len ) ;
	buff[rv]='\0';
	printf("%s",buff);
	close ( fd1) ;
}

