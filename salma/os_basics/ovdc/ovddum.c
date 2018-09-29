#include<stdio.h>
#include<fcntl.h>
#include<time.h>
#include<sys/resource.h>
#include<sys/time.h>
struct node
{
	int pid;
	int giffies;
}rc;
int ovc(int p)
{
	time_t now;
	time(&now);
	int t,i,j,x,y=0,diff,fd,r,w,p1;
	char buff[100];
	char warn[100]=" WARNING cpu occupancy is in between 30 and 40";
	char prio[100]="WARNING cpu occupancy is in between 40 and 50 priority is reduced";
	char susp[100]="WARNING cpu occupancy is above 50 process has suspended";
	fd=open("ovdc.log",O_CREAT|O_RDWR,0777);
	printf("---->fd value %d\n",fd);
	for(i=0;;i++)
	{
		for(j=0;j<5;j++)
		{
			r=read(p,&rc,12);
			printf("%d\n",rc.giffies);
			x=rc.giffies;
			diff=x-y;
			//printf("Difference :%d\n",diff);
			y=x;
			if(j>=1)
			{ 
			   printf("pid :%d \t difference :%d\n",rc.pid,diff);
				t=sprintf(buff,"Pid :%d\tDiff:%d\tTime:%s\n",rc.pid,diff,ctime(&now));
			w=write(fd,buff,t);
			if(diff>30 && diff<40)
			{
                t=sprintf(buff,"Pid:%d\tDiff:%d\tTime:%s\t%s\n",rc.pid,diff,ctime(&now),warn);
			write(fd,buff,t);
			}
            if(diff>40 && diff<50)
			{
              p1=getpriority(PRIO_PROCESS,rc.pid);
			  printf("----->getpriorty: %d\n",p1);
			  setpriority(PRIO_PROCESS,rc.pid,p1-5);
			  p1=getpriority(PRIO_PROCESS,rc.pid);
			  printf("----->set priorty:%d\n",p1);
             t=sprintf(buff,"Pid:%d\tDiff:%d\tTime:%s\t%s\n",rc.pid,diff,ctime(&now),prio);
		    	write(fd,buff,t);
			}
			if(diff>50)
			{
             kill(rc.pid,SIGSTOP);
			 t=sprintf(buff,"Pid:%d\tDiff:%d\tTime:%s\t%s\n",rc.pid,diff,ctime(&now),susp);
		     write(fd,buff,t);
			}
			
			}
		}
		sleep(1);
	}
}
