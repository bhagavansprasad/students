#include <stdio.h>
#include <fcntl.h>
main()
{
	int fp;
	char chr = 'A';
	int pid;
	pid = fork();
	if(pid == 0)
	{
		fp = open("baby",O_WRONLY,0666);
		printf("in chld chr is %c\n",chr);
		chr = 'B';
		write(fp,&chr,1);
		printf("in chld chr after chang %c\n",chr);
		printf("child exiting \n");
		close(fp);
	}
	else
	{
		wait((int *)0);
		fp = open("baby",O_RDONLY);
		read(fp,&chr,1);
		printf("chr after parent is %c\n",chr);
		close(fp);
	}
}
