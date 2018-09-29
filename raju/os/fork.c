#include<stdio.h>
#include<fcntl.h>


main()
{

	int pid;

	pid=fork();

	if(pid==0)
	{
		
		child();

	}

	else
	{

		parent();

	}

}


parent()
{
	char s[100];
	int r=0,l=6;

	int fd=open("os.txt", O_RDONLY, 0);

//	sleep(1);                                     printing 5 bytes two times

	do
	{
		r = read(fd, s, l);
	
		s[r]='\0';

		printf("r:%d\n",r);

		printf("s:%s\n",s);

		sleep(1);

	}while(r == l);


	close(fd);


}

	
child()
{
	char s[100];
	int r=0,l=5;

	int fd=open("os.txt", O_RDONLY, 0);

	

	do
	{
		r = read(fd, s, l);
	
		s[r]='\0';

		printf("r:%d\n",r);

		printf("s:%s\n",s);

		sleep(1);

	}while(r == l);


	close(fd);


}		




