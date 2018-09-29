#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
main()
{
	char *p1="hello world";
	//char *p1="hi world";
	char buff[50];
	int p[2],pid,len=10;

	pipe(p);
	pid=fork();
	if(pid > 0)
	{
		write(p[1],p1,len);
		//printf("write is %p\n",p1);
	}

	else
	{
		sleep(5);
		read(p[0],buff,len);
		printf("%s\n",buff);
	}

	exit(0);

}
