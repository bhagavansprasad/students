#include <stdio.h>
#include <fcntl.h>
	
	int i,j,rfd;
	int fd1,fd2,fd3,fd4;
	int k,l;
	int sub;
	
	int wc;
	int sum[5];
	int var1,var2;
	
	char str[20];
	char buff[500];

main()
{

	int pd;
	int rwd;
	pd = open("raghu",O_RDONLY,0);
	
	int ret1,ret2,ret3,ret4;
	fd1 = open("/proc/1790/stat",O_RDONLY,0);
	printf("fd1 == %d\n",fd1);
	rwd = write(pd,fd1,20);
	printf("write return value is %d\n",rwd);


	fd2 = open("/proc/1570/stat",O_RDONLY,0);
	printf("fd2 == %d\n",fd2);
	
	fd3 = open("/proc/1577/stat",O_RDONLY,0);
	printf("fd3 == %d\n",fd3);
	
	fd4 = open("/proc/1593/stat",O_RDONLY,0);
	printf("fd4 == %d\n",fd4);
	
}

