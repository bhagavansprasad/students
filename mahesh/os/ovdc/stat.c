#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
main()
{
	int fd,len = 10,rval,i,c=0,var1,var2=0,sum=0,y=0,x=0,diff=0;
	char buff[20],word[20];
	fd = open("/proc/3106/stat",O_RDONLY);
	if(fd < 0)
		printf("file open failure\n");
	for(i=0;i<5;i++)
	{
		while(1)
		{
			rval = read(fd,buff,len);
			buff[rval] = '\0';
			printf("%s",buff);
			if(rval < len)
			break;
   		}
			lseek(fd,58l,0);
			rval = read(fd,buff,20);
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
		lseek(fd,0l,0);
		printf("\n");
	}
	close(fd);
}
