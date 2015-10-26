#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
main()
{
	int pid,fd,rval;
	char *ch  = "hii";
	char *ch1 = "hello";
	char *ch2 = "hw r u";
	char *ch3 = "fine what abt u";
	char *ch4 = "fine what else";
	char *ch5 = "nothing bye";
	char *ch6 = "ok bye";
	char buff[50];
	fd = open("kumar",O_RDWR);
	pid = fork();
	if (pid == 0)
	{
		printf("------>in child process<-----\n\v");
		write(fd,ch,50);
		write(fd,ch2,50);
		sleep(1);
		//#if 0
		read(fd,buff,50);
		printf("from the parent :%s\n\v",buff);
		read(fd,buff,50);
		printf("from the parent :%s\n\v",buff);
		
		write(fd,ch4,50);
		write(fd,ch6,50);
		sleep(2);
		read(fd,buff,50);
		printf("from the parent :%s\n\v",buff);
		//#endif

	}
	else
	{
		printf("------>in parent process<-----\n");
		read(fd,buff,50);
		printf("from the child :%s\n\v",buff);
		read(fd,buff,50);
		printf("from the child :%s\n\v",buff);
        //#if 0
		write(fd,ch1,50);
		write(fd,ch3,50);
		sleep(2);
		read(fd,buff,50);
		printf("from the child :%s\n\v",buff);
		read(fd,buff,50);
		printf("from the child :%s\n\v",buff);
		write(fd,ch5,50);
		sleep(2);
		//#endif

	}

}
