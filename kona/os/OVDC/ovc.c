#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
struct student
{
	int pid;
	int giffies;
}rc;
char buf[100];
int l=20;
void ovc(int p)
{
int i, j, x, d, y = 0, r,gp,sp;
int fd=open("logfile.txt",O_CREAT|O_RDWR,0777);
int rval;
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
				{
				printf("pid :%d\t cpu occupancy is :%d\n", rc.pid, d);
				rval=sprintf(buf,"pid :%d\t difference is :%d\n", rc.pid, d);
				write(fd,buf,rval);
				 gp=getpriority(PRIO_PROCESS,rc.pid);
				printf("---->the priority val is :%d \t",gp);
				if(d>=30)
				{
				 sp=setpriority(PRIO_PROCESS,rc.pid,gp-5);
				printf("the set priority val is :%d \t",sp);
				}
			}
			}
		sleep(1);
	}	
}
