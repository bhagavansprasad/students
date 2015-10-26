#include <fcntl.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
struct student
{
	int pid;
	int giffies;
}rc;
int fd;
char buff[50];
int len=25;
void ovc(int p)
{
	int i, j, x, d, y = 0, r,rval,gval,pval;
	fd=open("t.txt",O_CREAT|O_RDWR,0664);
	for (j=0; ; j++)
	{
		for(i = 0;i<5  ; i++)
		{
			r=read(p,&rc,12);
			printf("%d\n",rc.giffies);
			x=rc.giffies;
			d=x-y;
			y=x;
			if(i>=1)
				rval=sprintf(buff,"pid %d\t difference %d\t ",rc.pid,d);
			write(fd,buff,rval);
			gval=getpriority(PRIO_PROCESS,rc.pid);
			printf("--------------->:priority%d\n",gval);
			setpriority(PRIO_PROCESS,rc.pid,-5);
			pval=getpriority(PRIO_PROCESS,rc.pid);
			printf("--------------->:priority%d\n",pval);

		}
		sleep(1);
	}
	close(fd);
}
