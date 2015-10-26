#include<stdio.h>
#include<fcntl.h>
main()
{
	int pid,fd,fd1,fd2,r1=0,r2=0,l1,l2;
	char buff1[100],buff2[100];
	//fd=open("t.txt",O_RDONLY,0777);
	//printf(" fd before fork :%d \n",fd);
	pid=fork();
	while(1)
	{
	if(pid==0)
	{
		fd1=open("t.txt",O_RDONLY,0777);
		printf(" fd in child :%d \n",fd1);
		printf("index in child :%d \n",r1);
		r1=read(fd1,buff1,5);
		l1=lseek(fd,r1,0);
		printf("index in child :%d \n",l1);
		sleep(1);
		if(r1<5)
		break;
	//	sleep(1);
	}
	else
	{
		fd2=open("t.txt",O_RDONLY,0777);
		printf(" fd in parent :%d \n",fd2);
		printf("index in parent :%d \n",r2);
		r2=read(fd2,buff2,10);
		printf(" r2 :%d\n ",r2);
		l2=lseek(fd,r2,1);
		printf("index in parent :%d \n",l2);
		sleep(1);
		if(r2<10)
		break;
	//	sleep(1);
	}
  } 
}
