#include<stdio.h>
#include<fcntl.h>
main()
{
	char s[100];
	int r=0,l=2;

	int fd=open("os.txt", O_RDONLY, 0);

	

	do
	{
		r = read(fd, s, l);
	
		s[r]='\0';

		printf("r:%d\n",r);

		printf("s:%s\n",s);

		sleep(2);

	}while(r == l);


	close(fd);


}	



