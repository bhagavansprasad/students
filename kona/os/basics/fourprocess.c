#include <stdio.h>
#include <fcntl.h>
main()
{
	int	i,j,r,l=12,v1,v2,v3,x,y=0,d;
	char buf[100];
	int fd[4];
	fd[0]=open("/proc/4009/stat",O_RDONLY);
	fd[1]=open("/proc/4018/stat",O_RDONLY);
	fd[2]=open("/proc/4025/stat",O_RDONLY);
	fd[3]=open("/proc/4042/stat",O_RDONLY);
	printf("-->fd0 val is:%d\n",fd[0]);
	printf("-->fd1 val is:%d\n",fd[1]);
	printf("-->fd2 val is:%d\n",fd[2]);
	printf("-->fd3 val is:%d\n",fd[3]);
	for(j=0;j<4;j++)
	{
		for(i=0;i<5;i++)
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
			x=v3;
			d=x-y;
			y=x;
			if(i>=1)
				printf("difference is :%d\n",d);
			sleep(2);
			lseek(fd[j],0l,0);
			printf("\n");
		}
		close(fd[j]);
	}
}	
