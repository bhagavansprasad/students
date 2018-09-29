#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd,pid,i=0,j=0,rval;
	char buff[20];
	char *q[]={"aaaa","bbbb","cccc"};
	char *a[]={"zzzz","yyyy","xxxx"};
	fd = open("tested",O_RDWR);
	pid = fork();
	if(pid > 0)
	{
		write(fd,q[i],20);
		sleep(2);
		i++;
		rval = read(fd,buff,20);
		buff[rval]='\0';
		printf("ms:recv: ans : %s\n",buff);
		write(fd,q[i],20);
		sleep(2);
		i++;
		rval = read(fd,buff,20);
		buff[rval]='\0';
		printf("ms:recv: ans : %s\n",buff);
		write(fd,q[i],20);
		sleep(2);
		i++;
		rval = read(fd,buff,20);
		buff[rval]='\0';
		printf("ms:recv: ans : %s\n",buff);
	}
	else
	{
		rval = read(fd,buff,20);
		buff[rval]='\0';
		printf("ch:recv: Q : %s\n",buff);
		write(fd,a[j],20);
		sleep(3);
		j++;
		rval = read(fd,buff,20);
		buff[rval]='\0';
		printf("ch:recv: Q : %s\n",buff);
		write(fd,a[j],20);
		sleep(2);
		j++;
		rval = read(fd,buff,20);
		buff[rval]='\0';
		printf("ch:recv: Q : %s\n",buff);
		write(fd,a[j],20);
		sleep(2);
		j++;
	}

}
