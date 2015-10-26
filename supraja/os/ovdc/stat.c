#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd,len=11,rval,i,v1,v2,v3,x,y=0,d;
	char buff[12];
	fd=open("/proc/5240/stat",O_RDONLY);
	if(fd<0)
	{
		printf("open failure");
	}
	for(i=0;i<5;i++)
	{
	while(1)
	{
		rval=read(fd,buff,len);
		buff[rval]='\0';
		printf("%s",buff);
		if(rval<len)
			break;
	}
	lseek(fd,59l,0);
	rval=read(fd,buff,len);
	buff[rval]='\0';
	printf("\n %s",buff);
	printf("\n");
	sscanf(buff,"%d %d ",&v1,&v2);
	v3=v1+v2;
	x=v3;
	d=x-y;
	y=x;
	printf("%d\n",v3);
	if(i>=1)
	  printf(" difference :%d\n",d);
	sleep(2);
	lseek(fd,0l,0);
	printf("\n");

	}

}
