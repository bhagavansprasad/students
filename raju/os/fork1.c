#include<stdio.h>
#include<fcntl.h>

main()
{

	int pid;

		char s[100];
		int r=0,l;

	int fd=open("os.txt", O_RDONLY, 0);


	pid=fork();

	if(pid==0)
	{

	//	char s[100];
	//	int r=0,l=5;

	l=5;

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

	else
	{

	//	char s[100];
	//	int r=0,l=6;

	l=6;

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

}

strings






