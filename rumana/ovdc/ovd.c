#include<stdio.h>
#include<fcntl.h>
struct student
{
	int pid;
	int giffies;
}s;
int ovd(int p)
{
	int i,j,r,v1,v2,v3,w,l=12;
	char buff[100];
	int a[4]={6949,7007,7065,7123};
	int fd[4];
	fd[0]=open("/proc/6949/stat",O_RDONLY);
	fd[1]=open("/proc/7007/stat",O_RDONLY);
	fd[2]=open("/proc/7065/stat",O_RDONLY);
	fd[3]=open("/proc/7123/stat",O_RDONLY);
	printf("fd0 val is %d\n",fd[0]);
	printf("fd1 val is %d\n",fd[1]);
	printf("fd2 val is %d\n",fd[2]);
	printf("fd3 val is %d\n",fd[3]);
	for(j=0;j<4;j++)
	{
		for(i=0;i<5;i++)
		{
			while(1)
			{
				r=read(fd[j],buff,12);
				buff[r]='\0';
				printf("%s",buff);
				if(r<l)
					break;
			}
			lseek(fd[j],59l,0);
			r=read(fd[j],buff,12);
			buff[r]='\0';
			printf("%s\n",buff);
			sscanf(buff,"%d %d",&v1,&v2);
			v3=v1+v2;
			s.giffies=v3;
			s.pid=a[j];
			write(p,&s,12);
			sleep(2);
			lseek(fd[j],0l,0);
			printf("\n");
		}
		close(fd);
	}
}
