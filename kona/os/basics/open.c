#include <stdio.h>
#include <fcntl.h>
main()
{
	int i,fd,r,l=10,v1,v2,v3,x,y=0,d;
	char buf[100];
	fd=open("/proc/2309/stat",O_RDONLY);
	fd=open("/proc/2753/stat",O_RDONLY);
	printf("-->fd val is:%d\n",fd);
	for(i=0;i<5;i++)
	{
		while(1)
		{
			r=read(fd,buf,10);
			buf[r]='\0';
			printf("%s",buf);
			if(r<l)
				break;
		}

		printf("\n");
		//printf("\n");
		//sleep(2);
		//lseek(fd,0l,0);
		lseek(fd,59l,0);
		r=read(fd,buf,10);
		buf[r]='\0';
		printf("%s",buf);
		sscanf(buf,"%d %d",&v1,&v2);
		v3=v1+v2;
		x=v3;
		d=x-y;
		y=x;
		if(i>=1)
		printf("\tdifference is :%d\n",d);
		sleep(2);
		lseek(fd,0l,0);
		printf("\n");
	}
	close(fd);
}
