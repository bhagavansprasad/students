#include<stdio.h>
#include <fcntl.h>
main()
{
	int fd,ln=10,r=0;
	
	char buf[100];
	
	fd=open("prasad.c",O_RDWR);
	
	printf("%d",fd);
	
	while(1)
	{

		r = read ( fd , buf , ln );
		
		buf[r] = '\0';
		
		printf(" %s " , buf);
		
		if( r < ln)
		break;
	}

    close( fd );
}


