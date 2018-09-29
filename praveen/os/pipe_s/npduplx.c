#include <stdio.h>
#include <fcntl.h>
main()
{
	int pid,fd,fd1,i = 0,j = 0,rval;
	char *buff[] = {"hii","hw r u"};
	char *buff1[] = { "hello","fine"};
	char max[20];
	fd = open("sai",O_RDWR);
	fd1 = open("siri",O_RDWR);
	pid = fork();
	if(pid == 0)
	{
		write(fd,buff[i],10);
		i++;
		rval = read(fd1,max,10);
		printf("the max val is:%d\n\v",rval);
		printf("from the parent :%s\n",max);
		write(fd,buff[i],10);
		i++;
		rval = read(fd1,max,10);
		printf("the max val is:%d\n\v",rval);
		printf("from the parent :%s\n",max);
	}
	else
	{
		rval = read(fd,max,10);
		printf("the max val is:%d\n\v",rval);
		printf("from the child :%s\n",max);
		write(fd1,buff1[j],10);
		j++;
		rval = read(fd,max,10);
		printf("the max val is:%d\n\v",rval);
		printf("from the child :%s\n",max);
		write(fd1,buff1[j],50);
		j++;
		
	}


}
