#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

main()
{
	int r,i=0,fd;
	char buf[200];
	fd = open("t.txt",O_RDONLY);

	while(1)
	{
		r=read(fd,buf,100);
		i=i+r;

		if(r<=0)
		{
			printf("the no of char is %d\n",i);
			break;
		}
	}
}











