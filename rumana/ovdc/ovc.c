#include<stdio.h>
struct student
{
	int pid;
	int giffies;
}rc;
void ovc(int p)
{
	int i,j,x,d,y=0,r;
	for(j=0;j<4;j++)
	{
		for(i=0;i<5;i++)
		{
			r=read(p,&rc,12);
			printf("%d\n",rc.giffies);
			x=rc.giffies;
			d=x-y;
			y=x;
			if(i>=1)
			{
				printf("pid is %d differece is %d\n",rc.pid,d);
			}
		}
	}
}
