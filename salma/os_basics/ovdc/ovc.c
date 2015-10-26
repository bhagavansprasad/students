#include<stdio.h>
#include<fcntl.h>
#include<time.h>
struct node
{
	int pid;
	int giffies;
}rc;
int ovc(int p)
{
	time_t now;
	time(&now);
	int t,i,j,x,y=0,diff,fd,r,w;
	char buff[100];
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
			y=x;
			if(j>=1)
			{ 
			   printf("pid :%d \t difference :%d\n",rc.pid,diff);
				t=sprintf(buff,"pid :%d\tDiff:%d\ttime:%s",rc.pid,diff,ctime(&now));
			w=write(fd,buff,t);
			}
		}
		sleep(1);
	}
}
