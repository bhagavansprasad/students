#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "afun.h"
 #include <errno.h>


main()
{
<<<<<<< main.c
	int fd , fd2 , r_val_read=0 , r_val_write=0 , len=10; 
=======
	int fd=0,fd2=0,r_val_read=0,r_val_write=0,len=10; 
>>>>>>> 1.2
	char buff[100];

<<<<<<< main.c
	fd  = aopen("t.txt",O_RDONLY,0);
	printf("fd : ->%d\n", fd);

	fd2=aopen("t2.txt",O_CREAT|O_WRONLY,0777);
	printf("fd2 : %d\n", fd2);

=======
	fd  =aopen("t.txt",O_RDONLY,0);
	printf("fd:->%d\n",fd);
	fd2 =aopen("t2.txt",O_CREAT|O_WRONLY,0777);
	printf("%d\n",fd2);
>>>>>>> 1.2
	while(1)
	{
<<<<<<< main.c

		r_val_read = aread(  fd,  buff,  len);
		printf("read return : %d\n", r_val_read);
		buff[r_val_read]='\0';
		r_val_write = awrite(  fd2 ,  buff ,  r_val_read);
		if(-1)
		{
	
		perror("cnnot write\r\n");
				
			printf("read return : %d\n", r_val_write);
			break;
		}
		if ( r_val_read < len)
=======
		r_val_read = aread( fd, buff, len);
		printf("read return%d\n",r_val_read);
		r_val_write = awrite( fd2, buff, len);
    	printf("read return%d\n",r_val_write);
		if(r_val_read<len)
>>>>>>> 1.2
			break;

	}

	aclose( fd2 );

	aclose( fd );

}

