#include<stdio.h>
#include<fcntl.h>
#include<time.h>
#include<sys/resource.h>
#include<sys/time.h>
#include<signal.h>
struct node
{
	int pid;
	int giffies;
}rc;
int ovc(int p)
{
	time_t now;
	time(&now);
	int i,j,x,y=0,diff,fd,r,w,p1,len=12,t;
	char buff[100];
	char  warn[]="WARNING CPU OCCUPENCY IS IN BETWEEN 20 AND 30";
	char prio[]="WARNING CPU OCCUPENCY IS IN BETWEEN 30 AND 40 PRIORITY IS REDUCED";
	char susp[]="CPU OCCUPENCY IS ABOVE 40 SO PROCESS IS SUSPENDED";
	fd=open("ovdc.log",O_CREAT|O_RDWR,0777);
	printf("fd value is %d\n",fd);
	for(i=0;;i++)
	{
		for(j=0;j<5;j++)
		{
			r=read(p,&rc,len);
			printf("%d\n",rc.giffies);
			x=rc.giffies;
			diff=x-y;
			y=x;
			if(j>=1)
			{
				printf("pid is %d\t difference is %d\t \n",rc.pid,diff);
				t=sprintf(buff,"pid:%d\t diff:%d\t time:%s\n",rc.pid,diff,ctime(&now));
				w=write(fd,buff,t);
			}
			if(diff>20 && diff<30)
			{
				t=sprintf(buff,"pid:%d\t diff:%d\t time:%s\t warn:%s\n",rc.pid,diff,ctime(&now),warn);
				write(fd,buff,t);
			}
			if(diff>30 && diff<40)
			{
				p1=getpriority(PRIO_PROCESS,rc.pid);
				printf("get priority is %d\n",p1);
				setpriority(PRIO_PROCESS,rc.pid,p1-5);
				p1=getpriority(PRIO_PROCESS,rc.pid);
				printf("set priority is %d\n ",p1);
				t=sprintf(buff,"%d\t %d\t %s\t %s\n",rc.pid,diff,ctime(&now),prio);
				write(fd,buff,t);
			}
			if(diff>40)
			{
				kill(rc.pid,SIGSTOP);
				t=sprintf(buff,"pid:%d\t difference:%d\t time:%s\t susp%s",rc.pid,diff,ctime(&now),susp);
				write(fd,buff,t);
			}
		}
	}
	sleep(1);
}
