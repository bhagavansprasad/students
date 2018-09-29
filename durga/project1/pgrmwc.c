#include<stdio.h>
#include<fcntl.h>
main()
{
	int r, fd, ln = 10, i, j, s = 0, c=0,k=0;

	char buf[100];
	
	fd = open( "prasad.c", O_RDWR );
	 
	 printf(" %d \n",fd);

	while(1)
	{
		r = read(fd, buf, ln);
		s += r;
		buf[r] = '\0';
		for(i = 0; buf[i] != '\0'; i++)
		{
			if( buf[i] == '\n')
				c++;
		if( buf[i] == ' ' && buf[j=i-1]!=' ' && buf[j]!='\0' )
		k++;
		 		
		}
		 
		 if( r < ln)
			break;
	}
	printf(" %d\t%d\t%d\n", c,k, s);
	close(fd);

}
