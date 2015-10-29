#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
main()
{
	int fd[4];
	char buff[20];
	int f,len=10,rval,i,c=0,var1,var2=0,sum=0,y=0,x=0,diff=0;
	fd[0]=open("/proc/5079/stat",O_RDONLY);
	fd[1]=open("/proc/5138/stat",O_RDONLY);
	fd[2]=open("/proc/5194/stat",O_RDONLY);
	fd[3]=open("/proc/5249/stat",O_RDONLY);
	for(f=0;f<4;f++)
	{
		for(i=0;i<5;i++)
		{
			while(1)
			{
				rval=read(fd[f],buff,len);
				buff[rval]='\0';
				printf("%s",buff);
				if(rval<len)
					break;
			}
			lseek(fd[f],58l,0);
			rval=read(fd[f],buff,20);
			buff[rval]='\0';
			sscanf(buff,"%d %d",&var1,&var2);
			printf("var1: %d\t var2: %d\n",var1,var2);
			sum=var1+var2;
			x=sum;
			diff=x-y;
			y=sum;
			if(i>=1)
				printf("cpu occupancy is :%d\n",diff);
			sleep(2);
			lseek(fd[f],0l,0);
			printf("\n");
		}
		close(fd[f]);
	}
}
