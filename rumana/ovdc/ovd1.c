#include<stdio.h>
#include<fcntl.h>
struct node
{
	int pid;
	int giffies;
}s;
int ovd(int p)
{
	int i,j,v1,v2,v3,r,len=12;
	int fd[4];
	int a[4]={13977,14032,14087,14142};
	char buff[100];
	fd[0]=open("/proc/13977/stat",O_RDONLY);
	fd[1]=open("/proc/14032/stat",O_RDONLY);
	fd[2]=open("/proc/14087/stat",O_RDONLY);
	fd[3]=open("/proc/14142/stat",O_RDONLY);
	printf("fd of [0] is %d\n",fd[0]);
	printf("fd of [1] is %d\n",fd[1]);
	printf("fd of [2] is %d\n",fd[2]);
	printf("fd of [3] is %d\n",fd[3]);
	for(i=0;;i++)
	{
		for(j=0;j<5;j++)
		{
			while(1)
			{
				r=read(fd[i],buff,len);
				buff[r]='\0';
				printf("%s",buff);
				if(r<len)
					break;
			}
			lseek(fd[i],59l,0);
			r=read(fd[i],buff,len);
			buff[r]='\0';
			printf("%s\n",buff);
			sscanf(buff,"%d %d",&v1,&v2);
			v3=v1+v2;
			s.giffies=v3;
			//printf("giffess in ovd:%d",v3);
			s.pid=a[i];
			write(p,&s,len);
			sleep(2);
			lseek(fd[i],0l,0);
			printf("\n");
		}
		close(fd[i]);
	}
}
