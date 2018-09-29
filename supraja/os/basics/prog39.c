#include<stdio.h>
#include<fcntl.h>
main()
{
	int fp;
	char buff[11];
	int pid;
	fp=open("baby",O_RDONLY);
	pid=fork();
	if(pid==0)
	{
		printf("child begins %d\n",getpid());
		read(fp,buff,10);
		buff[10]='\0';
		printf("child read :");
		puts(buff);
		printf("child exiting\n");
	}
	else
	{
		read(fp,buff,10);
		buff[10]='\0';
		printf("parent read :");
		puts(buff);
		printf("parent exiting\n");
	}
}

