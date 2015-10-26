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
	int i, j, x, d, y = 0, r,rval,gval,sval;
	fd=open("t.txt",O_CREAT|O_RDWR,0664);
	for (j=0; ; j++)
	{
		d=0;
		for(i = 0;i<5  ; i++)
		{
			r=read(p,&rc,12);
			printf("%d\n",rc.giffies);
			x=rc.giffies;
			d=x-y;
			y=x;
			if(i<1)
				d=0;
			else if(i>=1)
				printf("pid %d\t difference %d\t ",rc.pid,d);
			rval=sprintf(buff,"pid %d\t difference %d\n ",rc.pid,d);
			write(fd,buff,rval);
			gval=getpriority(PRIO_PGRP,rc.pid);
			printf("--------------->:priority%d\n",gval);
			//if(gval>=2&&gval<=10)
			sval=setpriority(PRIO_PGRP,rc.pid,0);
			printf("------------->:sval is %d\n",sval);


		}
		sleep(1);
	}
	close(fd);
}
