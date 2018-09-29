#include <stdio.h>
#include <fcntl.h>
struct student
{
	int pid;
	int giffies;
}s,rc;
main()
{
	int	i,j,r,w,l=12,v1,v2,v3,x,y=0,d;
	char buf[100];
	int p[2],pid;
	int fd[4];
	int a[]={3709,3724,3738,3751};
	fd[0]=open("/proc/3709/stat",O_RDONLY);
	fd[1]=open("/proc/3724/stat",O_RDONLY);
	fd[2]=open("/proc/3738/stat",O_RDONLY);
	fd[3]=open("/proc/3751/stat",O_RDONLY);
	printf("-->fd0 val is:%d\n",fd[0]);
	printf("-->fd1 val is:%d\n",fd[1]);
	printf("-->fd2 val is:%d\n",fd[2]);
	printf("-->fd3 val is:%d\n",fd[3]);
	pipe(p);
	pid=fork();
	if(pid>0)
	{
		for(j=0;j<4;j++)
		{
			for(i=0;i<5;i++)
			{
				r=read(p[0],&rc,12);
				printf("%d\n",s.giffies);
				x=s.giffies;
				d=x-y;
				y=x;
				if(i>=1)
				printf("difference is :%d\n",d);
			}
		}
	}
	else
	{
		for(j=0;j<4;j++)
		{
			for(i=0;i<5;i++)
			{
				while(1)
				{
					r=read(fd[j],buf,w);
					buf[r]='\0';
					printf("%s",buf);
					if(r<w)
						break;
					sleep(1);
				}
				lseek(fd[j],59l,0);
				r=read(fd[j],buf,12);
				buf[r]='\0';
				printf("%s\n",buf);
				sscanf(buf,"%d %d",&v1,&v2);
				v3=v1+v2;
				s.giffies=v3;
				s.pid=a[j];
				w=write(p[1],&s,10);
				sleep(2);
				lseek(fd[j],0l,0);
				printf("\n");
			}
			close(fd[j]);
		}
	}	
}
