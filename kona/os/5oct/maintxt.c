#include <stdio.h>
#include <fcntl.h>
int d;
main()
{
	int fd1,fd2,r;
	int l=10;
	char buff[100];
	int pid=fork();
	if(pid>0)
	{
		fd1=open("t.txt",O_RDONLY,0);
		printf("--->the file pointer in parent is %d\n",d);
		sleep(2);

		printf("--->the file pointer in parent is %d\n",d);
		r=read(fd1,buff,l);
		d=lseek(fd1,0,1);
		//printf("--->the value of d is %d\n",d);
		printf("--->the file pointer in parent second time is %d\n",d);
		sleep(2);
		r=read(fd1,buff,l);
		d=lseek(fd1,0,1);
		printf("--->the file pointer in parent thrid time is %d\n",d);
	}
	else
	{
		fd2=open("t.txt",O_RDONLY,0);
		r=read(fd2,buff,l);
		d=lseek(fd2,0,1);
		printf("--->the file pointer in child is %d\n",d);
		sleep(2);
		r=read(fd2,buff,l);
		d=lseek(fd2,0,1);
		printf("--->the file pointer in child second time is %d\n",d);
		sleep(2);	
	}
	close(fd1);
	close(fd2);
}
