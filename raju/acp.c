#include<stdio.h>
#include<fcntl.h>
main()
{
	char s[100];
	int r=0,w=0,l=10;

	int fd1=open("g", O_RDONLY, 0),fd2;
	printf("fd1:%d\n",fd1);

	fd2 = open("h", O_CREAT | O_RDWR, 0777); // creat or append
	printf("fd2:%d\n",fd2);

	do
	{
		r = read(fd1, s, l);
		w = write(fd2, s, r);
		printf("%d\n",w);
	}while(r == l);


	close(fd1);
	close(fd2);

}	



