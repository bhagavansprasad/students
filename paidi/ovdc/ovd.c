#include "stdio.h"
#include "stdlib.h"
#include "ovdc.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int ovd(int wfd)

{
	
	int pid[100]={2073,2074,2075,2076,2077,2078,2079};
	int giffs,i,retval,n;
	n=7;
	printf(" ovd pid==%d\n",getpid());
	ovdc_data data;
	
	while(1)
	{ 
		for(i=0;i<n;i++)
		{
			giffs =get_giffies_pid(pid[i]);
			if(giffs!=-1)
				send_giffies(wfd, pid[i],giffs);
		}
		data.pid=-1;
		data.giffs=-1;
		retval = write(wfd, &data, sizeof(data));
	}

	sleep(5);

}
int send_giffies(int wfd, int pid, int giffies)
{
	int retval,i;
	ovdc_data data;		
		data.pid = pid;
		data.giffs = giffies;
		retval = write(wfd, &data, sizeof(data));

		if(retval <= 0)
		{
			perror("writing file is failed");
			return -1;
		} 

}
int get_giffies_pid(int pid)
{
	int p[2],retval,cg,pg=0,fd;
	char s1[30];
	char buff[300];

	int i,a,b,c,d,j,k;

	sprintf(s1,"/proc/%d/stat",pid);

	fd = open(s1,O_RDONLY);
	if(fd < 0)   
	{
		printf("opeing file failed\n");
		return -1;
	}

	retval=read(fd,buff,300);
	buff[retval]='\0';

	for(i=0,j=0;i<=300&&j<=12;i++)
	{
				if(buff[i]==' '||buff[i]=='\n')
			{
				j++;
			}
		
	}
	sscanf(&buff[i], "%d %d %d %d\n", &a, &b, &c, &d);

	printf("\na=%d b=%d   c= %d d=%d  sum=%d \n",a,b,c,d ,a + b + c + d);

	sleep(1);
	cg=a+b+c+d;
	return cg;

	close(fd);
}


