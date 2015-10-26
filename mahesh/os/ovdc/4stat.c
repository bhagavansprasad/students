#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
main()
{
	int f,len = 10,rval,i,c=0,var1,var2=0,sum=0,y=0,x=0,diff=0;
	char buff[20],word[20];
	int fd[4];
	fd[0] = open("/proc/4520/stat",O_RDONLY);
	fd[1] = open("/proc/4533/stat",O_RDONLY);
	fd[2] = open("/proc/4549/stat",O_RDONLY);
	fd[3] = open("/proc/4564/stat",O_RDONLY);
	//if(fd < 0)
	//	printf("file open failure\n");
	for(f=0; f < 4; f++)
	{
		for(i=0;i<5;i++)
		{
			while(1)
			{
				rval = read(fd[f],buff,len);
				buff[rval] = '\0';
				printf("%s",buff);
				if(rval < len)
					break;
			}
			lseek(fd[f],58l,0);
			rval = read(fd[f],buff,20);
			buff[rval] = '\0';
			//printf("\n%s",buff);
			sscanf(buff,"%d   %d",&var1,&var2);
			printf("var 1 : %d\t var 2 : %d\n",var1,var2);
			sum = var1+var2;
			x = sum;
			diff = x - y;
			y = sum;
			if(i >= 1)
				printf("CPU OCCUPANCY : %d\n",diff);
			sleep(2);
			lseek(fd[f],0l,0);
			printf("\n");
		}
		close(fd[f]);
	}
}
