#include <stdio.h>
#include <fcntl.h>
struct student
{
	int pid;
	int giffies;
}s;
int ovd(int p)
{

	int i,j,r,v1,v2,v3,w,l=12;
	char buf[100];
	int a[]={2813,2880,3056,3123};
	int fd[4];
	fd[0]=open("/proc/2813/stat",O_RDONLY);
	fd[1]=open("/proc/2880/stat",O_RDONLY);
	fd[2]=open("/proc/3056/stat",O_RDONLY);
	fd[3]=open("/proc/3123/stat",O_RDONLY);
	printf("-->fd0 val is:%d\n",fd[0]);
	printf("-->fd1 val is:%d\n",fd[1]);
	printf("-->fd2 val is:%d\n",fd[2]);
	printf("-->fd3 val is:%d\n",fd[3]);

	for(j=0;;j++)
		{
			for(i=0;i<5 ;i++)
			{
				while(1)
				{
					r=read(fd[j],buf,12);
					buf[r]='\0';
					printf("%s",buf);
					if(r<l)
						break;
				}
				lseek(fd[j],59l,0);
				r=read(fd[j],buf,12);
				buf[r]='\0';
				printf("%s\n",buf);
				sscanf(buf,"%d %d",&v1,&v2);
				v3=v1+v2;
				s.giffies=v3;
				s.pid=a[j];
				w=write(p,&s,12);
				sleep(2);
				lseek(fd[j],0l,0);
				printf("\n");

			}
			close(fd[j]);
		}
	}	
